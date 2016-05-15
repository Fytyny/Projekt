#include "projekt.h"
#include "Zwnswn.h"
#include "DatabaseConnection.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QDate>
#include <cmath>
using namespace std;

QDebug operator<< (QDebug d, const Zwnswn &c) {
	d << "Hello world!";
	return d;
}

int main(int argc, char *argv[])
{
	DatabaseConnection base;
	int check = base.connect();
	if (check) 
	{
		qDebug() << "Can't open database";
		return 0;
		//exit(0);sad

	}
	else
	{
		qDebug() << "Database openeed successfully";
	}
	QApplication a(argc, argv);
	Projekt w;

	w.show();
	const QDate curr = QDate::currentDate();
	Zwnswn jot;
	jot << qDebug();
	qDebug() << "jot" << jot;
	return a.exec(); 
}

