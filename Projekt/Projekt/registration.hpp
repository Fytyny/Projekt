#pragma once
#include <QWidget>
#include "ui_registration.h"
#include "DatabaseConnection.h"

class Registration : public QWidget {
	Q_OBJECT

public:
	Registration(QWidget * parent = Q_NULLPTR, DatabaseConnection * db = NULL);
	~Registration();

public slots:
	void send();

private:
	Ui::Registration ui;
	DatabaseConnection * db;
};
