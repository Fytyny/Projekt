#include "Person.h"
#include <string>
#include <sstream>
#include <QDebug>
using namespace std;

template <typename T>
T onlyFirst(char** argv)
{
	return static_cast<T>(atol(argv[0]));
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

long long Person::getAccountNumber()
{
	return this->accountNumber;
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
					tmp->id = onlyFirst<int>(argv);
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
				tmp->accNum = onlyFirst<unsigned long long>(argv);
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

bool Person::getPersonFromDataBase(string login, string password, DatabaseConnection* db)
{
	struct X {
		bool check = false;
		static int callback(void *data, int argc, char **argv, char **azColName)
		{
			X* tmp = static_cast<X*>(data);
			tmp->check = true;
			if (argv[0] == NULL)
			{
				return 1;
			}
			else
			{
			}
			return 0;
		}
	};
	X tmp;
	string query = "select * from accounts where Login = '" + login + "' AND Password = '" + password + "'";
	int rc = db->execute(query, tmp.callback, &tmp);
	return tmp.check;

}