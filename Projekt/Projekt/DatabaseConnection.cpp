#include "DatabaseConnection.h"
#include <sqlite3.h>
#include <QDebug>


DatabaseConnection::DatabaseConnection()
{
	
}


DatabaseConnection::~DatabaseConnection()
{
	sqlite3_close(db);
	
}

int DatabaseConnection::connect() 
{
	int rc;
	rc = sqlite3_open("Clients.db", &this->db);
	return rc;
}