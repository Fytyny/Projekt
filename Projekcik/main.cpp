#include "projekcik.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Projekcik w;
	w.show();
	return a.exec();
}
