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

string Person::toAccounts()
{
	stringstream result;
	result << "insert into accounts values ";
	result << "(" << this->id << ", '" << this->login << "', '" << this->password << "')";
	string statement = result.str();
	return statement;

}

string Person::toDetails()
{
	stringstream result;
	result << "insert into details values ";
	result << "(" << this->id << ", '" << this->firstName << "', '" << this->secondName << "', '" << this->lastName << "')";
	string statement = result.str();
	return statement;
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
	db->execute("select max(ID) from accounts", tmp.callback, &tmp);
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
	result << "(" << getID() << ", '" << getAccountNumber() << "')";
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