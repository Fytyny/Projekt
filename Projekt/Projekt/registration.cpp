#include "registration.hpp"
#include "Person.h"
#include "DatabaseConnection.h"
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <string>
#include <sstream>
using namespace std;
Registration::Registration(Projekt * parent, DatabaseConnection * db) 
{
	ui.setupUi(this);
	this->db = db;
	this->parent = parent;
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

		p.generateID(this->db);
		p.generateAccountNumber(this->db);
		
		int err = p.insertIntoDb(this->db);
		
		if (err == 3)
		{
			notify.setText("Cannot connect to database.");
			notify.setIcon(QMessageBox::Critical);
			notify.exec();
		}
		else if (err > 0)
		{
			stringstream info;
			p.deleteFromDb(this->db);
			info << err;
			notify.setText("Error, cannot create account." + QString::fromStdString(info.str()));
			notify.setIcon(QMessageBox::Critical);
			notify.exec();
		}
		else
		{
			notify.setText("Account created successfully!");
			notify.setIcon(QMessageBox::Information);
			notify.exec();
			goBack();
		}
		
	}
	
}

void Registration::goBack()
{
	parent->setLoginScreen();
}