#pragma once
#include <QWidget>
#include "ui_moneyexchange.h"
#include "projekt.h"
#include "DatabaseConnection.h"
#include "Person.h"

class MoneyExchange : public QWidget {
	Q_OBJECT

public:
	MoneyExchange(Projekt * parent, DatabaseConnection* db);
	~MoneyExchange();
	double checkPLN(QString);
	double checkUSD(QString);
	double checkEUR(QString);
	int send(double moneyS, double moneyR, Person receiver);
public slots:
	void sendMoney();
	void goBack();
private:
	Ui::MoneyExchange ui;
	Projekt* parent;
	DatabaseConnection* db;
};
