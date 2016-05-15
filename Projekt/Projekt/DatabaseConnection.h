#pragma once
#include <sqlite3.h>
class DatabaseConnection
{
	sqlite3 *db;
public:
	DatabaseConnection();
	~DatabaseConnection();
	int connect();
};

