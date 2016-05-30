#include "registration.hpp"
#include "Person.h"
#include "DatabaseConnection.h"
#include <QDebug>
#include <QMessageBox>
#include <string>
#include <sstream>
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
		p.generateID(this->db);
		p.generateAccountNumber(this->db);
		stringstream result;
		int err = 0;
		result << "insert into accounts values ";
		result << "(" << p.getID() << ", '" << p.getLogin() << "', '" << p.getPassword() << "')";
		err += db->execute(result.str());
		result.str(std::string());
		result << "insert into details values ";
		result << "(" << p.getID() << ", '" << p.getFirstName() << "', '" << p.getSecondName() << "', '" << p.getLastName() << "')";
		err += db->execute(result.str());
		result.str(std::string());
		result << "insert into numbers values ";
		result << "(" << p.getID() << ", '" << p.getAccountNumber() << "')";
		err += db->execute(result.str());
		result.str(std::string());
		if (err == 3)
		{
			notify.setText("Cannot connect to database.");
			notify.setIcon(QMessageBox::Critical);
			notify.exec();
		}
		else if (err > 0)
		{
			result << "delete from accounts where ID = " << p.getID();
			db->execute(result.str());
			result.str(std::string());
			result << err;
			notify.setText("Error, cannot create account." + QString::fromStdString(result.str()));
			notify.setIcon(QMessageBox::Critical);
			notify.exec();
		}
		else
		{
			notify.setText("Account created successfully!");
			notify.setIcon(QMessageBox::Information);
			notify.exec();
			close();
		}
		
	}
}
