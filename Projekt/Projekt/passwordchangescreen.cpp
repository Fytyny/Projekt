#include "passwordchangescreen.hpp"
#include "Projekt.h"
#include "Person.h"
#include "DatabaseConnection.h"
#include <QMessageBox>

PasswordChangeScreen::PasswordChangeScreen(Projekt * parent, DatabaseConnection* db) : QWidget(parent) {
	ui.setupUi(this);
	this->parent = parent;
	this->db = db;
}

PasswordChangeScreen::~PasswordChangeScreen() {
	
}

void PasswordChangeScreen::goBack()
{
	parent->setAccountViewScreen();
}

void PasswordChangeScreen::updatePassword()
{
	QMessageBox notify;
	if (ui.password->text().compare(QString::fromStdString(parent->getPerson()->getPassword())) != 0)
	{
		notify.setText("It's not your password.");
		notify.setIcon(QMessageBox::Warning);
		notify.exec();
	}
	else if (ui.newPassword->text().compare(ui.confirmNewPassword->text()) != 0 )
	{
		notify.setText("Passwords does not much.");
		notify.setIcon(QMessageBox::Warning);
		notify.exec();
	}
	else
	{
		parent->getPerson()->setPassword(ui.newPassword->text().toStdString());
		if (parent->getPerson()->updatePassword(db) != 0)
		{
			notify.setText("Error can't connect to DB.");
			notify.setIcon(QMessageBox::Critical);
			notify.exec();
			parent->getPerson()->setPassword(ui.password->text().toStdString());
		}
		else
		{
			notify.setText("Password has been changed successfully.");
			notify.setIcon(QMessageBox::Information);
			notify.exec();
			parent->setAccountViewScreen();
		}
	}
}