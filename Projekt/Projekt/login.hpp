#pragma once
#include <QWidget>
#include <qmainwindow.h>
#include "ui_login.h"
#include "Person.h"
#include "DatabaseConnection.h"
class Login : public QWidget {
	Q_OBJECT

public:
	Login(QMainWindow * parent = Q_NULLPTR, DatabaseConnection * db = NULL);
	~Login();
public slots:
	void send();
private:
	DatabaseConnection * db;
	Ui::Login ui;

};
