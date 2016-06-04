#pragma once
#include <sqlite3.h>
#include <string>
using namespace std;
class DatabaseConnection
{
	sqlite3 *db;
	
	
public:
	DatabaseConnection();
	~DatabaseConnection();
	int connect();
	int disconnect();
	int createTabAccounts();
	int dropTabAccounts();
	int createTabDetails();
	int dropTabDetails();
	int createTabNumbers();
	int dropTabNumbers();
	int execute(const char*);
	int execute(string);
	int execute(string, int(*)(void*, int, char**, char**), void*);
};

