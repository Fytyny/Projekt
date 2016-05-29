#include "registration.hpp"
#include "Person.h"
#include "DatabaseConnection.h"
#include <QDebug>
#include <QMessageBox>
#include <string>
using namespace std;
Registration::Registration(QWidget * parent, DatabaseConnection * db) 
{
	ui.setupUi(this);
	this->db = db;
}

Registration::~Registration() 
{

}

void Registration::send() 
{
	Person p;
	QMessageBox notify;
	if (ui.firstName->text().isEmpty() || ui.secondName->text().isEmpty() || ui.lastName->text().isEmpty() || ui.login->text().isEmpty() || ui.password->text().isEmpty() || ui.confirmPassword->text().isEmpty()) 
	{
		notify.setText("Please fill in all fields.");
		notify.setIcon(QMessageBox::Information);
		notify.exec();
	}
	else if (ui.password->text().compare(ui.confirmPassword->text()) != 0)
	{
		notify.setText("Passwords does not much.");
		notify.setIcon(QMessageBox::Information);
		notify.exec();
	}
	else 
	{
		p.setFirstName(ui.firstName->text().toStdString());
		p.setSecondName(ui.secondName->text().toStdString());
		p.setLastName(ui.lastName->text().toStdString());
		p.setLogin(ui.login->text().toStdString());
		p.setPassword(ui.password->text().toStdString());
		close();
	}
}
