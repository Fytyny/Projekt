#include "login.hpp"
#include "Person.h"
#include <QMessageBox>

Login::Login(QMainWindow * parent, DatabaseConnection * db) : QWidget(parent)
{
	ui.setupUi(this);
	this->db = db;
	
}

Login::~Login()
{
	
}

void Login::send()
{
	QMessageBox notification;
	Person s;
	if (!ui.login->text().isEmpty() && !ui.password->text().isEmpty()) {
		if (s.getPersonFromDataBase(ui.login->text().toStdString(), ui.password->text().toStdString(), db) == true)
		{
			notification.setIcon(QMessageBox::Information);
			notification.setText("Successfully logged into account.");
			notification.exec();
			close();
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