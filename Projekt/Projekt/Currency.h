#pragma once
#include <string>
using namespace std;
class Currency
{
	Currency* state;
	double cash;
	string type = "PLN";
public:
	Currency();
	~Currency();
	void setCash(double, string);
	double getCash();
	string getType();

};

struct PLN : Currency 
{
	double toUSD()
	{
		return this->getCash() / 3.9139556;
	}
	double toEUR()
	{
		return this->getCash() / 4.4161161;
	}
	double toPLN()
	{
		return this->getCash();
	}
};

struct USD : Currency
{
	double toPLN()
	{
		return this->getCash() / 0.255496;
	}
	double toEUR()
	{
		return this->getCash() / 1.1283;
	}
	double toUSD()
	{
		return this->getCash();
	}
};

struct EUR : Currency
{
	double toPLN()
	{
		return this->getCash() / 0.226443322;
	}
	double toUSD()
	{
		return this->getCash() / 0.886289108;
	}
	double toEUR()
	{
		return this->getCash();
	}
};


