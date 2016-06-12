#pragma once
#include <QWidget>
#include <qmainwindow.h>
#include "ui_accountview.h"
#include "projekt.h"
#include "Person.h"
#include "DatabaseConnection.h"

class AccountView : public QWidget {
	Q_OBJECT

public:
	AccountView(Projekt * parent, DatabaseConnection* db, Person * user);
	~AccountView();
public slots:
	void logOut();
	void showPersonData();
	void sendMoney();

private:
	Ui::AccountView ui;
	Person* user;
	Projekt* parent;
};
