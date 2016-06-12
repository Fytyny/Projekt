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

struct PLN {
	double cash;
	double toUSD();
};


