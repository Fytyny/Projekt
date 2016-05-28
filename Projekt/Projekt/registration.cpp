#include "registration.hpp"
#include "Person.h"
#include <QDebug>
#include <QMessageBox>
Registration::Registration(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);


}

Registration::~Registration() 
{
	
}

void Registration::send() 
{
	Person p;
	QMessageBox notify;
	qDebug() << "checked " << ui.firstName->text();
	if (ui.firstName->text().isEmpty() || ui.secondName->text().isEmpty() || ui.lastName->text().isEmpty() || ui.login->text().isEmpty() || ui.password->text().isEmpty() || ui.confirmPassword->text().isEmpty()) 
	{
		notify.setText("Please fill in all fields");
		notify.setIcon(QMessageBox::Information);
		notify.exec();
	}
}
