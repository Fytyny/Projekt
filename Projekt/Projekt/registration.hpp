#pragma once
#include <QWidget>
#include "projekt.h"
#include "ui_registration.h"
#include "DatabaseConnection.h"

class Registration : public QWidget {
	Q_OBJECT

public:
	Registration(Projekt * parent = NULL, DatabaseConnection * db = NULL);
	~Registration();

public slots:
	void send();
	void goBack();

private:
	Ui::Registration ui;
	DatabaseConnection * db;
	Projekt * parent;
};
