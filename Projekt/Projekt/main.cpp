#include "projekt.h"
#include "Zwnswn.h"
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
	int check = base.connect();
	if (check != SQLITE_OK)  
	{
		qDebug() << "Can't open database";
		exit(0);

	}
	else
	{
		qDebug() << "Database openeed successfully ";
	}
	base.createTAB();
	
	

	/*
	QApplication a(argc, argv);
	Projekt w;

	w.show();
	const QDate curr = QDate::currentDate();
	Zwnswn jot;
	jot << qDebug();
	qDebug() << "jot" << jot;

	return a.exec(); 
	*/
	return 0;
}

