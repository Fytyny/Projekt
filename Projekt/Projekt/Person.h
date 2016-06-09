#pragma once
#include <string>
#include "DatabaseConnection.h"
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
public:
	Person();
	~Person();
	bool getPersonFromDataBase(string,string, DatabaseConnection*);
	string getFirstName();
	string getSecondName();
	string getLastName();
	int getID();
	string getLogin();
	string getPassword();
	void setFirstName(string);
	void setSecondName(string);
	void setLastName(string);
	void setLogin(string);
	void setPassword(string);
	long long getAccountNumber();
	void generateID(DatabaseConnection*);
	void generateAccountNumber(DatabaseConnection*);
	string toAccounts();
	string toDetails();
	string toNumbers();
	int insertIntoDb(DatabaseConnection*);
	int deleteFromDb(DatabaseConnection*)
	
};

