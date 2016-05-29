#include "DatabaseConnection.h"
#include <sqlite3.h>
#include <QDebug>
#include <thread>
#include <string>
#include <chrono>
using namespace std::chrono_literals;
using namespace std;

DatabaseConnection::DatabaseConnection()
{
	
}
DatabaseConnection::~DatabaseConnection()
{
	int d = disconnect();
}

int DatabaseConnection::disconnect()
{
	int rc = sqlite3_close(this->db);
	while (rc == SQLITE_BUSY) 
	{
		rc = sqlite3_close(this->db);
		std::this_thread::sleep_for(1s);
	}
	qDebug() << "Successfully disconnected db";
	return rc;
}

int DatabaseConnection::connect() 
{
	int rc = sqlite3_open("Clients.db", &this->db);
	return rc;
}

int DatabaseConnection::execute(char* newStatement)
{
	char* sf;
	int rc = sqlite3_exec(this->db, newStatement, NULL, NULL, &sf);
	return rc;
}
int DatabaseConnection::createTAB()
{
	char * statement = "create table users (Id int primary key, Login nvarchar(100) not null , Password nvarchar(100) not null )";
    return this->execute(statement);
}

int DatabaseConnection::dropTAB()
{
	char * statement = "drop table users";
	return this->execute(statement);
}