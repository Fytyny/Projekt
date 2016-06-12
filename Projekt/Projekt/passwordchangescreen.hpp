#pragma once
#include <QWidget>
#include "ui_passwordchangescreen.h"
#include "DatabaseConnection.h"
#include "Projekt.h"


class PasswordChangeScreen : public QWidget {
	Q_OBJECT

public:
	PasswordChangeScreen(Projekt * parent, DatabaseConnection * db);
	~PasswordChangeScreen();
public slots:
	void goBack();
	void updatePassword();
private:
	Ui::PasswordChangeScreen ui;
	Projekt* parent;
	DatabaseConnection* db;
};
