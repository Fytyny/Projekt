#include "login.hpp"
#include "Person.h"
#include <QMessageBox>
#include <projekt.h>

Login::Login(Projekt * parent, DatabaseConnection * db) : QWidget(parent)
{
	ui.setupUi(this);
	this->db = db;
	this->parent = parent;
}

Login::~Login()
{
	
}

void Login::send()
{
	QMessageBox notification;
	Person * s = new Person;
	if (!ui.login->text().isEmpty() && !ui.password->text().isEmpty()) {
		if (s->getPersonFromDataBase(ui.login->text().toStdString(), ui.password->text().toStdString(), db) == 0)
		{
			notification.setIcon(QMessageBox::Information);
			notification.setText("Successfully logged into account.");
			notification.exec();
			parent->setPerson(s);
			parent->setAccountViewScreen();
		}
		else
		{
			notification.setIcon(QMessageBox::Critical);
			notification.setText("Incorrect login or password.");
			notification.exec();
		}
	}
	else
	{
		notification.setIcon(QMessageBox::Warning);
		notification.setText("Some fields are empty");
		notification.exec();
	}
}

void Login::regButton()
{
	parent->setRegistrationScreen();
	
}