#include "MoneyExchange.hpp"
#include "DatabaseConnection.h"
#include "projekt.h"
#include "Currency.h"
#include <qmessagebox.h>
#include <sstream>
#include <qdebug.h>


using namespace std;

template <typename T>
double toPLN(double cash)
{
	T retVal;
	retVal.setCash(cash, "");
	return retVal.toPLN();
}

template <typename T>
double toUSD(double cash)
{
	T retVal;
	retVal.setCash(cash, "");
	return retVal.toUSD();
}

template <typename T>
double toEUR(double cash)
{
	T retVal;
	retVal.setCash(cash, "");
	return retVal.toEUR();
}

void showMessage(QString txt, QMessageBox::Icon icon)
{
	QMessageBox st;
	st.setIcon(icon);
	st.setText(txt);
	st.exec();
}
MoneyExchange::MoneyExchange(Projekt * parent, DatabaseConnection* db) : QWidget(parent) {
	ui.setupUi(this);
	this->parent = parent;
	this->db = db;
}

MoneyExchange::~MoneyExchange() {
	
}

void MoneyExchange::sendMoney()
{
	Person s;
	if (ui.accNum->text().toLongLong() < 1000000000000000 || ui.accNum->text().toLongLong() > 9999999999999999)
	{
		showMessage("Account number need to have 16 numbers ", QMessageBox::Warning);
	}
	else if (s.getID() == parent->getPerson()->getID())
	{
		showMessage("You cant send money to yourself! ", QMessageBox::Warning);
	}
	else if (ui.amountOfMoney->text().toDouble() > this->parent->getPerson()->getCurrency()->getCash())
	{
		showMessage("You don't have that many ", QMessageBox::Warning);
	}
	else if (ui.amountOfMoney->text().toDouble() <= 0)
	{
		showMessage("You cant send no money", QMessageBox::Warning);
	}
	else if (s.getPersonByNumber(ui.accNum->text().toLongLong(), db) != 0)
	{
		showMessage("There is no account number like that in db ", QMessageBox::Critical);
	}
	else if (s.getID() == parent->getPerson()->getID())
	{
		showMessage("You can't send money to yourself! ", QMessageBox::Warning);
	}
	else if (s.getPersonByNumber(ui.accNum->text().toLongLong(), db) == 0)
	{
		bool isOk;
		double moneyToSend;
		double moneyToReceive;
		if (ui.comboBox->currentText().compare("PLN") == 0)
		{
			moneyToSend = checkPLN(QString::fromStdString(parent->getPerson()->getCurrency()->getType()));
			moneyToReceive = checkPLN(QString::fromStdString(s.getCurrency()->getType()));

		}
		else if (ui.comboBox->currentText().compare("USD") == 0)
		{
	
			moneyToSend = checkUSD(QString::fromStdString(parent->getPerson()->getCurrency()->getType()));
			moneyToReceive = checkUSD(QString::fromStdString(s.getCurrency()->getType()));
		}
		else if (ui.comboBox->currentText().compare("EUR") == 0)
		{
			moneyToSend = checkEUR(QString::fromStdString(parent->getPerson()->getCurrency()->getType()));
			moneyToReceive = checkEUR(QString::fromStdString(s.getCurrency()->getType()));
		}
		else
		{
			showMessage("Critical error that shouln't ever occur! ", QMessageBox::Critical);
			return;
		}

		if (moneyToSend <= this->parent->getPerson()->getCurrency()->getCash())
		{
			int tc;
			if (tc = send(moneyToSend, moneyToReceive, s) != 0)
			{
				showMessage("There was problem with DB nr " + QString::number(tc), QMessageBox::Critical);
			}
			else
			{
				showMessage("Money sent successfully", QMessageBox::Information);
			}
		}
		else
		{
			showMessage("You don't have that many ", QMessageBox::Warning);
		}

	}

}

double MoneyExchange::checkPLN(QString a)
{
	double retVal;
	if (a.compare(ui.comboBox->currentText()) != 0)
	{
		if (a.compare("USD") == 0)
		{
			retVal = toUSD<PLN>(ui.amountOfMoney->text().toDouble());
		}
		else
		{
			retVal = toEUR<PLN>(ui.amountOfMoney->text().toDouble());
		}
	}
	else
	{
		retVal = ui.amountOfMoney->text().toDouble();
	}
	return retVal;
}

double MoneyExchange::checkUSD(QString a)
{
	double retVal;
	if (a.compare(ui.comboBox->currentText()) != 0)
	{
		if (a.compare("EUR") == 0)
		{
			retVal = toEUR<USD>(ui.amountOfMoney->text().toDouble());
		}
		else
		{
			retVal = toPLN<USD>(ui.amountOfMoney->text().toDouble());
		}
	}
	else
	{
		retVal = ui.amountOfMoney->text().toDouble();
	}
	return retVal;
}

double MoneyExchange::checkEUR(QString a)
{
	double retVal;
	if (a.compare(ui.comboBox->currentText()) != 0)
	{
		if (a.compare("USD") == 0)
		{
			retVal = toUSD<EUR>(ui.amountOfMoney->text().toDouble());
		}
		else
		{
			retVal = toPLN<EUR>(ui.amountOfMoney->text().toDouble());
		}
	}
	else
	{
		retVal = ui.amountOfMoney->text().toDouble();
	}
	return retVal;
}

void MoneyExchange::goBack()
{
	parent->setAccountViewScreen();
}

int MoneyExchange::send(double moneyS, double moneyR, Person receiver)
{
	Currency* user = this->parent->getPerson()->getCurrency();
	user->setCash(user->getCash() - moneyS, user->getType());


	
	Currency* address = receiver.getCurrency();

	address->setCash(address->getCash() + moneyR, address->getType());


	stringstream query;
	query << "update numbers set amountOfMoney = " << user->getCash() << " where userID = " << parent->getPerson()->getID();
	int rc = 0;
	rc = db->execute(query.str());
	
	if (rc != 0) showMessage("1", QMessageBox::Critical);

	query.str(std::string());
	query << "update numbers set amountOfMoney = " << address->getCash() << " where userID = " << receiver.getID();
	rc = db->execute(query.str());

	if (rc != 0) showMessage("2", QMessageBox::Critical);
	query.str(std::string());
	query << "insert into notify values ('" << parent->getPerson()->getID() << "', '" << receiver.getID() << "', '1', '" << moneyS << "', '" << user->getType() << "', CURRENT_TIMESTAMP )";
	rc = db->execute(query.str());

	if (rc != 0) showMessage("3", QMessageBox::Critical);
	query.str(std::string());
	query << "insert into notify values ('" << receiver.getID() << "', '" << parent->getPerson()->getID() << "', '0' , '" << moneyR << "', '" << address->getType() << "' ,CURRENT_TIMESTAMP )";
	rc = db->execute(query.str());

	if (rc != 0) showMessage("4", QMessageBox::Critical);
	return rc;
}