#include "projekt.h"
#include "Zwnswn.h"
#include "registration.hpp"
#include "Person.h"
#include "DatabaseConnection.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QDate>
#include <cmath>
#include <string>
using namespace std;

QDebug operator<< (QDebug d, const Zwnswn &c) {
	d << "Hello world!";
	return d;
}

int main(int argc, char *argv[])
{
	DatabaseConnection base;
	if (base.connect() == SQLITE_OK)  
	{
		qDebug() << "Database openeed successfully ";
		

	}
	else
	{
		qDebug() << "Can't open database";
		exit(0);
	}

	qDebug() << base.createTabAccounts();
	qDebug() << base.createTabDetails();
	qDebug() << base.createTabNumbers();
	qDebug() << base.createTabNotify();

	QApplication a(argc, argv);

	Projekt main(NULL, &base);
	
	main.show();

	return a.exec();
}

