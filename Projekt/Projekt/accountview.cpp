#include "accountview.hpp"
#include "projekt.h"
#include "DatabaseConnection.h"
#include "Currency.h"
#include <string>
#include <sstream>
#include <QMessageBox>
#include <QDebug>
#include <QTextBrowser>
using namespace std;
AccountView::AccountView(Projekt * parent, DatabaseConnection * db, Person * user) : QWidget(parent) 
{
	ui.setupUi(this);
	this->user = user;
	this->parent = parent;
	this->db = db;
	char format;
	int prec;
	ui.cashAmount->display(QString::number(user->getCurrency()->getCash(), format = 'g', prec = 3));
	ui.type->setText(QString::fromStdString(user->getCurrency()->getType()));
	ui.FirstName->setText(QString::fromStdString(user->getFirstName()));
	ui.LastName->setText(QString::fromStdString(user->getLastName()));
	loadNotify();
}

AccountView::~AccountView()
{
	
}

int AccountView::loadNotify()
{
	ui.textBrowser->setText("");
	struct X {
		static int callback(void* data, int argc, char ** argv, char ** err)
		{
			QTextBrowser* wsk = static_cast<QTextBrowser*>(data);
			bool giver = atoi(argv[2]);
			QString result;
			if (giver)
			{
				result.append(QString::fromLatin1(argv[5]) + " You sent " + QString::fromLatin1(argv[3]) + " " + QString::fromLatin1(argv[4]) + " to user id = " + QString::fromLatin1(argv[1]));
			}
			else
			{
				result.append(QString::fromLatin1(argv[5]) + " You received " + QString::fromLatin1(argv[3]) + " " + QString::fromLatin1(argv[4]) + " from user id = " + QString::fromLatin1(argv[1]));
			}
			wsk->append(result + "\n");
			return 0;
		}
	};
	X tmp;
	stringstream query;
	query << "select * from notify where userID = " << parent->getPerson()->getID()<<" order by data desc";
	int rc = db->execute(query.str(), tmp.callback, ui.textBrowser);
	if (rc != 0)
	{
		QMessageBox st;
		st.setIcon(QMessageBox::Critical);
		st.setText("Can't access to Database error nr. " + QString::number(rc));
	}
	return rc;
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
	parent->setMoneyExchangeScreen();
}

void AccountView::cleanNotify()
{
	stringstream query;
	query << "delete from notify where userID = " << parent->getPerson()->getID();
	int rc = this->db->execute(query.str());
	if (rc != 0)
	{
		QMessageBox st;
		st.setIcon(QMessageBox::Critical);
		st.setText("Can't access to Database error nr. " + QString::number(rc) );
	}
	else
	{
		loadNotify();
	}
}