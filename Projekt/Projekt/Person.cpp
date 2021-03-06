#include "Person.h"
#include <string>
#include <sstream>
#include <QDebug>
using namespace std;

template <typename T>
T onlyFirst(char** argv, int i)
{
	return static_cast<T>(atoll(argv[i]));
	
}



Person::Person()
{

}

Person::~Person()
{
}

string Person::getFirstName()
{
	return this->firstName;
}

string Person::getSecondName()
{
	return this->secondName;
}

string Person::getLastName()
{
	return this->lastName;
}

int Person::getID()
{
	return this->id;
}

string Person::getLogin() 
{
	return this->login;
}

string Person::getPassword() 
{
	return this->password;
}

void Person::setFirstName(string first) 
{
	this->firstName = first;
}

void Person::setSecondName(string second)
{
	this->secondName = second;
}

void Person::setLastName(string last)
{
	this->lastName = last;
}

void Person::setLogin(string login)
{
	this->login = login;
}

void Person::setPassword(string password)
{
	this->password = password;
}

unsigned long long Person::getAccountNumber()
{
	return this->accountNumber;
}

void Person::setID(int id)
{
	this->id = id;
}


void Person::generateID(DatabaseConnection* db)
{
	if (this->id == 0)
	{
		struct ID {
			int id;
			static int callback(void *data, int argc, char **argv, char **azColName)
			{
				ID* tmp = static_cast<ID*>(data);
				if (argv[0] != NULL)
				{
					tmp->id = onlyFirst<int>(argv, 0);
					tmp->id++;
				}
				else
				{
					tmp->id = 1;
				}
				return 0;
			}
		};
		ID tmp;
		db->execute("select max(ID) from accounts", tmp.callback, &tmp);
		this->id = tmp.id;
	}
}

void Person::generateAccountNumber(DatabaseConnection* db)
{
	struct ACC {
		unsigned long long accNum;
		static int callback(void *data, int argc, char **argv, char **azColName)
		{
			ACC* tmp = static_cast<ACC*>(data);
			if (argv[0] != NULL)
			{
				tmp->accNum = onlyFirst<unsigned long long>(argv,0);
				tmp->accNum++;
			}
			else
			{
				tmp->accNum = 1000000000000000;
			}
			return 0;
		}
	};
	ACC tmp;
	int nowy [26];
	db->execute("select max(accountNumber) from numbers", tmp.callback, &tmp);
	this->accountNumber = tmp.accNum;
	
}

int Person::getPersonFromDataBase(string login, string password, DatabaseConnection* db)
{
	struct X {
		static int getID(void *data, int argc, char **argv, char **azColName)
		{

			Person* wsk = static_cast<Person*>(data);
			wsk->setID(onlyFirst<int>(argv, 0));
			return 1;
		}
		static int getPrimaryInfo(void *data, int argc, char **argv, char **azColName)
		{
			Person* wsk = static_cast<Person*>(data);
			wsk->setFirstName(argv[1]);
			wsk->setSecondName(argv[2]);
			wsk->setLastName(argv[3]);
			return 1;

		}
		static int getNumber(void *data, int argc, char **argv, char **azColName)
		{
			Person* wsk = static_cast<Person*>(data);
			wsk->setAccountNumber(onlyFirst<unsigned long long>(argv, 1));
			double s;
			s = std::stod(static_cast<string>(argv[2]));
			string t = argv[3];
			wsk->getCurrency()->setCash(s, t);
			return 1;
		}
	};
	X tmp;
	string query = "select * from accounts where Login = '" + login + "' AND Password = '" + password + "'";
	int rc = db->execute(query, tmp.getID, this);
	if (rc == SQLITE_ABORT)
	{
		this->login = login;
		this->password = password;
		int err = rc;
		stringstream res;
		res << "select * from details where UserID = '" << id << "'";
		err += db->execute(res.str(), tmp.getPrimaryInfo, this);
		res.str(std::string());
		res << "select * from numbers where UserID = '" << id << "'";
		err += db->execute(res.str(), tmp.getNumber, this);
		if (err != 12)
		{
			return 12;
		}
	} 
	else
	{
		return 1;
	}
	return 0;

}

int Person::getPersonByNumber(unsigned long long number, DatabaseConnection* db)
{
	struct X {
		static int getID(void *data, int argc, char **argv, char **azColName)
		{

			Person* wsk = static_cast<Person*>(data);
			wsk->setID(onlyFirst<int>(argv, 0));
			Currency* s = wsk->getCurrency();
			s->setCash(std::stod(static_cast<string>(argv[2])), static_cast<string>(argv[3]));

			return 1;
		}
		static int getPrimaryInfo(void *data, int argc, char **argv, char **azColName)
		{
			Person* wsk = static_cast<Person*>(data);
			wsk->setFirstName(argv[1]);
			wsk->setSecondName(argv[2]);
			wsk->setLastName(argv[3]);
			return 1;

		}
	};
	this->accountNumber = number;
	X tmp;
	stringstream res;
	res << "select * from numbers where accountNumber = " << number;
	int rc = db->execute(res.str(), tmp.getID, this);
	if (rc == SQLITE_ABORT)
	{
		int err = rc;
		res.str(std::string());
		res << "select * from details where UserID = '" << id << "'";
		err += db->execute(res.str(), tmp.getPrimaryInfo, this);
		if (err != 8)
		{
			return 8;
		}
	}
	else
	{
		return 1; //mark, 1 means that callback hasn't been called 
	}
	return 0;
}

int Person::insertIntoDb(DatabaseConnection* db)
{
	int err = 0;
	stringstream result;

	result << "insert into accounts values ";
	result << "(" << getID() << ", '" << getLogin() << "', '" << getPassword() << "')";
	err += db->execute(result.str());
	result.str(std::string()); //stringstream clear
	
	result << "insert into details values ";
	result << "(" << getID() << ", '" << getFirstName() << "', '" << getSecondName() << "', '" << getLastName() << "')";
	err += db->execute(result.str());
	result.str(std::string());

	result << "insert into numbers values ";
	result << "(" << getID() << ", '" << getAccountNumber() << "' ,'"<< 10 <<"' ,'"<<vault.getType() <<"')";
	err += db->execute(result.str());
	result.str(std::string());

	return err;

}

int Person::deleteFromDb(DatabaseConnection* db)
{
	stringstream result;
	result << "delete from accounts where ID = " << getID();
	return db->execute(result.str());
	
}

void Person::setAccountNumber(unsigned long long i)
{
	this->accountNumber = i;
}

Currency* Person::getCurrency()
{
	return &this->vault;
}
int Person::updatePassword(DatabaseConnection* db)
{
	stringstream query;
	query << "update accounts set password = '"<< getPassword() <<"' where ID = " << getID();
	return db->execute(query.str());
}