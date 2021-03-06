#pragma once
#include <string>
#include "DatabaseConnection.h"
#include "Currency.h"
using namespace std;
class Person
{
	string firstName;
	string secondName;
	string lastName;
	int id = 0;
	string login;
	string password;
	unsigned long long accountNumber;
	Currency vault;
	
public:
	Person();
	~Person();
	int getPersonFromDataBase(string,string, DatabaseConnection*);
	int getPersonByNumber(unsigned long long number, DatabaseConnection* db);
	string getFirstName();
	string getSecondName();
	string getLastName();
	void setID(int id);
	int getID();
	string getLogin();
	string getPassword();
	void setFirstName(string);
	void setSecondName(string);
	void setLastName(string);
	void setLogin(string);
	void setPassword(string);
	unsigned long long getAccountNumber();
	void setAccountNumber(unsigned long long);
	void generateID(DatabaseConnection*);
	void generateAccountNumber(DatabaseConnection*);
	int updatePassword(DatabaseConnection*);
	int updateCash(DatabaseConnection*);
	int insertIntoDb(DatabaseConnection*);
	int deleteFromDb(DatabaseConnection*);
	Currency* getCurrency();

};

