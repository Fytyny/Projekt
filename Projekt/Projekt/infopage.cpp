#include "infopage.hpp"
#include "DatabaseConnection.h"
#include "Projekt.h"
#include "Currency.h"
#include "Person.h"
#include <qmessagebox.h>
#include <sstream>
using namespace std;




template <class T>
void toUSD(Currency* cur, DatabaseConnection* db)
{
	T* aid = static_cast<T*>(cur);
	double d = aid->toUSD();
	aid->setCash(d, "USD");
}

template <class T>
void toPLN(Currency* cur, DatabaseConnection* db)
{
	T* aid = static_cast<T*>(cur);
	double d = aid->toPLN();
	aid->setCash(d, "PLN");
}

template <class T>
void toEUR(Currency* cur, DatabaseConnection* db)
{
	T* aid = static_cast<T*>(cur);
	double d = aid->toEUR();
	aid->setCash(d, "EUR");
}


void showBox(QString txt)
{
	QMessageBox st;
	st.setIcon(QMessageBox::Critical);
	st.setText(txt);
	st.exec();
}

infoPage::infoPage(Projekt * parent, DatabaseConnection* db) : QWidget(parent) {
	
	ui.setupUi(this);
	
	ui.firstName->setText(QString::fromStdString(parent->getPerson()->getFirstName()));
	ui.SecondName->setText(QString::fromStdString(parent->getPerson()->getSecondName()));
	ui.LastName->setText(QString::fromStdString(parent->getPerson()->getLastName()));
	ui.accNumber->setText(QString::number(parent->getPerson()->getAccountNumber()));
	
	this->db = db;
	this->parent = parent;
	Currency* personCur = parent->getPerson()->getCurrency();
	QString curType = QString::fromStdString(personCur->getType());
	
	if (curType.compare("PLN") == 0)
	{
		ui.comboBox->setCurrentIndex(0);
	}
	else if (curType.compare("USD") == 0)
	{
		ui.comboBox->setCurrentIndex(1);
	}
	else
	{
		ui.comboBox->setCurrentIndex(2);
	}
	

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

void infoPage::changeType()
{
	Currency* personCur = parent->getPerson()->getCurrency();
	QString curType = QString::fromStdString(personCur->getType());
	
	if (curType.compare("PLN") == 0)
	{
		if (ui.comboBox->currentText().compare("USD") == 0 )
		{
			toUSD<PLN>(personCur, db);
		}
		else if (ui.comboBox->currentText().compare("EUR") == 0)
		{
			toEUR<PLN>(personCur, db);
		}
		else
		{
			showBox("Cannot Proceed this action");
		}
	} 
	else if (curType.compare("EUR") == 0)
	{
		if (ui.comboBox->currentText().compare("PLN") == 0)
		{
			toPLN<EUR>(personCur, db);
		}
		else if (ui.comboBox->currentText().compare("USD") == 0)
		{
			toUSD<EUR>(personCur, db);
		}
		else
		{
			showBox("Cannot Proceed this action");
		}
	}
	else if (curType.compare("USD") == 0)
	{
		if (ui.comboBox->currentText().compare("EUR") == 0)
		{
			toEUR<USD>(personCur, db);
		}
		else if (ui.comboBox->currentText().compare("PLN") == 0)
		{
			toPLN<USD>(personCur, db);
		}
		else
		{
			showBox("Cannot Proceed this action");
		}
	}
	else
	{
		showBox("Cannot Proceed this action");
	}

	stringstream query;
	query << "update numbers set amountOfMoney = " << personCur->getCash() << ", typeOfMoney = '" << personCur->getType() << "' where UserID = " << this->parent->getPerson()->getID();
	int rc = db->execute(query.str());
	if (rc != 0)
	{
		showBox("There was a problem with database please try again later");
	}
}

