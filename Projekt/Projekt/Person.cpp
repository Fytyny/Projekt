#include "Person.h"

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

string Person::getPassowrd() 
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

void Person::setID(int id)
{
	this->id = id;
}

char* Person::toStatement()
{
	return NULL;
}
