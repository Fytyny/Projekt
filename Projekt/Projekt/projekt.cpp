#include "projekt.h"
#include "registration.hpp"
#include "login.hpp"
#include "accountview.hpp"
#include "passwordchangescreen.hpp"
#include "infopage.hpp"
#include "MoneyExchange.hpp"
#include <QStackedWidget>
#include <qcombobox.h>
#include <qdebug.h>

Projekt::Projekt(QWidget *parent, DatabaseConnection * db)
	: QMainWindow(parent)
{
	this->db = db;
	ui.setupUi(this);
	pageController = new IntelligentPTR(this);
	setLoginScreen();
}

Projekt::~Projekt()
{
	delete pageController;
}

void Projekt::setPerson(Person* p)
{
	this->user = p;
}

void Projekt::setRegistrationScreen()
{
	pageController->setPage(new Registration(this, db));
}

void Projekt::setLoginScreen()
{
	pageController->setPage(new Login(this, db));
}

void Projekt::setAccountViewScreen()
{
	pageController->setPage(new AccountView(this, db, user));
}

void Projekt::setInfoScreen()
{
	pageController->setPage(new infoPage(this, db));
}
void Projekt::deletePerson()
{
	delete user;
}

Person* Projekt::getPerson()
{
	return user;
}
void Projekt::setPasswordChangeScreen()
{
	pageController->setPage(new PasswordChangeScreen(this,db));
}

void Projekt::setMoneyExchangeScreen()
{
	pageController->setPage(new MoneyExchange(this, db));
}