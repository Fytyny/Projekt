#include "Zwnswn.h"
#include <QDebug>
#include <QDate>


Zwnswn::Zwnswn()
{
	qDebug() << "Nowa klasa Zwnswn";
	int rok = this->podejrz();
	qDebug() << rok;
}


Zwnswn::~Zwnswn()
{
}

int Zwnswn::podejrz() {
	return QDate::currentDate().year();
}

QDebug Zwnswn::operator<<(QDebug debug)
{
	QDebugStateSaver saver(debug);
	debug.nospace() << this->podejrz() << " Yo ";

	return debug;
}
