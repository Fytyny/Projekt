#pragma once
#include <QWidget>
#include "ui_infopage.h"
#include "DatabaseConnection.h"
#include "Projekt.h"
#include "Person.h"

class infoPage : public QWidget {
	Q_OBJECT

public:
	infoPage(Projekt * parent, DatabaseConnection* db);
	~infoPage();

public slots:
	void passwordChange();
	void goBack();
	void changeType();

private:
	Ui::infoPage ui;
	Projekt* parent;
	DatabaseConnection* db;
};
