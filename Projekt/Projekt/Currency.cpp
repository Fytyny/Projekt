#include "Currency.h"
#include <string>
using namespace std;

Currency::Currency()
{
}


Currency::~Currency()
{
}

void Currency::setCash(double cash, string type)
{
	this->cash = cash;
	this->type = type;
}

double Currency::getCash()
{
	return this->cash;
}

string Currency::getType()
{
	return this->type;
}