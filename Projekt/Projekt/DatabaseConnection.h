#pragma once
#include <sqlite3.h>
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
};

