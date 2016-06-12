#include "accountview.hpp"
#include "projekt.h"
#include "DatabaseConnection.h"
#include "Currency.h"
#include <QMessageBox>

AccountView::AccountView(Projekt * parent, DatabaseConnection * db, Person * user) : QWidget(parent) 
{
	ui.setupUi(this);
	this->user = user;
	this->parent = parent;
	ui.cashAmount->display(user->getCurrency()->getCash());
	ui.type->setText(QString::fromStdString(user->getCurrency()->getType()));
	ui.FirstName->setText(QString::fromStdString(user->getFirstName()));
	ui.LastName->setText(QString::fromStdString(user->getLastName()));
}

AccountView::~AccountView()
{
	
}

void AccountView::logOut()
{
	QMessageBox st;
	st.setIcon(QMessageBox::Information);
	st.setText("Logged Out");
	parent->deletePerson();
	st.exec();
	parent->setLoginScreen();

}

void AccountView::showPersonData()
{
	parent->setInfoScreen();
}

void AccountView::sendMoney()
{

}