#include "projekt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Projekt w;
	w.show();
	return a.exec();
}
