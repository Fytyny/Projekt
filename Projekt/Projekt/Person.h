#pragma once
#include <string>
#include "DatabaseConnection.h"
using namespace std;
class Person
{
	string firstName;
	string secondName;
	string lastName;
	int id;
	string login;
	string password;
public:
	Person();
	~Person();
	string getFirstName();
	string getSecondName();
	string getLastName();
	int getID();
	string getLogin();
	string getPassowrd();
	void setFirstName(string);
	void setSecondName(string);
	void setLastName(string);
	void setID(int);
	void setLogin(string);
	void setPassword(string);
	int generateID(DatabaseConnection * db);
	char* toStatement();

};

