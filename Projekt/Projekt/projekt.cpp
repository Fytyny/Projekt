#include "projekt.h"
#include "registration.hpp"
#include "login.hpp"
#include <QStackedWidget>
#include <qcombobox.h>
#include <qdebug.h>

Projekt::Projekt(QWidget *parent, DatabaseConnection * db)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Login * firstPage = new Login(this, db);
	
	setCentralWidget(firstPage);
	
}

Projekt::~Projekt()
{
	
}
