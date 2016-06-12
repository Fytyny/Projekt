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
		this_thread::sleep_for(1s);
	}
	qDebug() << "Successfully disconnected db";
	return rc;
}

int DatabaseConnection::connect() 
{
	int rc = sqlite3_open("Clients.db", &this->db);
	return rc;
}

int DatabaseConnection::execute(const char* newStatement)
{
	char* sf;
	int rc = sqlite3_exec(this->db, newStatement, NULL, NULL, &sf);
	return rc;
}

int DatabaseConnection::execute(string newStatement)
{
	
	char* sf = strdup(newStatement.c_str());
	int rc = sqlite3_exec(this->db, sf, NULL, NULL, NULL);
	return rc;
}

int DatabaseConnection::execute(string newStatement, int (*callback)(void*, int, char** , char**), void *data )
{
	char* sf = strdup(newStatement.c_str());
	int rc = sqlite3_exec(this->db, sf, callback, data, NULL);
	return rc;
}
int DatabaseConnection::createTabAccounts()
{
	char * statement = "create table accounts (ID int primary key not null, Login nvarchar(100) not null unique , Password nvarchar(100) not null)";
    return this->execute(statement);
}

int DatabaseConnection::dropTabAccounts()
{
	char * statement = "drop table accounts";
	return this->execute(statement);
}

int DatabaseConnection::createTabDetails()
{
	char * statement = "create table details (userID int, firstName nvarchar(100) , secondName nvarchar(100), lastName nvarchar (100), foreign key(userID) references accounts(ID) on delete cascade )";
	return this->execute(statement);
}

int DatabaseConnection::dropTabDetails()
{
	char * statement = "drop table details";
	return this->execute(statement);
}

int DatabaseConnection::createTabNumbers()
{
	char * statement = "create table numbers (userID int, accountNumber unsigned bigint, amountOfMoney real, typeOfMoney nvarchar(3), foreign key(userID) references accounts(ID) on delete cascade )";
	return this->execute(statement);
}
int DatabaseConnection::dropTabNumbers()
{
	char * statement = "drop table numbers";
	return this->execute(statement);
}

int DatabaseConnection::createTabNotify()
{
	char * statement = "create table notify (userID int, giverID , giver boolean, amountOfMoney real, typeOfMoney nvarchar(3), data datetime, foreign key(userID) references accounts(ID) on delete cascade )";
	return this->execute(statement);
}

int DatabaseConnection::dropTabNotify()
{
	char * statement = "drop table notify";
	return this->execute(statement);
}