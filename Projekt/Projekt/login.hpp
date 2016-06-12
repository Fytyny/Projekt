#pragma once
#include <QWidget>
#include <qmainwindow.h>
#include "ui_login.h"
#include "Person.h"
#include "Projekt.h"
#include "DatabaseConnection.h"
class Login : public QWidget {
	Q_OBJECT

public:
	Login(Projekt * parent = Q_NULLPTR, DatabaseConnection * db = NULL);
	~Login();
public slots:
	void send();
	void regButton();
private:
	DatabaseConnection * db;
	Ui::Login ui;
	Projekt * parent;

};
