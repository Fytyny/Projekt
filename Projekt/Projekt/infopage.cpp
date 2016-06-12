#include "infopage.hpp"
#include "DatabaseConnection.h"
#include "Projekt.h"
#include "Person.h"

infoPage::infoPage(Projekt * parent) : QWidget(parent) {
	ui.setupUi(this);
	ui.firstName->setText(QString::fromStdString(parent->getPerson()->getFirstName()));
	ui.SecondName->setText(QString::fromStdString(parent->getPerson()->getSecondName()));
	ui.LastName->setText(QString::fromStdString(parent->getPerson()->getLastName()));
	ui.accNumber->setText(QString::number(parent->getPerson()->getAccountNumber()));
	this->parent = parent;
}

infoPage::~infoPage() {
	
}

void infoPage::goBack()
{
	this->parent->setAccountViewScreen();
}

void infoPage::passwordChange()
{
	this->parent->setPasswordChangeScreen();
}