#include "projekcik.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QDate>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);
	//Projekcik w;
	//w.show();
	const QDate curr = QDate::currentDate();
	int qwerty = 2324;
	qDebug() << "Date:" << curr;
	qDebug() << qwerty;
	qDebug() << "sgoksg";
	int i = curr.day();
	qDebug() << i;
	//return a.exec();
	return 0;
}
