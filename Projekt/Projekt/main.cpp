#include "projekt.h"
#include "Zwnswn.h"
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
	QApplication a(argc, argv);
	Projekt w;
	w.show();
	const QDate curr = QDate::currentDate();
	Zwnswn jot;
	jot << qDebug();
	qDebug() << "jot" << jot;
	//return a.exec();
	return 0;
}

