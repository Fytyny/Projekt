#pragma once
#include <sqlite3.h>
#include <string>
using namespace std;
class DatabaseConnection
{
	sqlite3 *db;
	int execute(char*);
	
public:
	DatabaseConnection();
	~DatabaseConnection();
	int connect();
	int disconnect();
	int createTAB();
	int dropTAB();
};

