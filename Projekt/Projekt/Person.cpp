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

