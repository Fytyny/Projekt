#ifndef PROJEKT_H
#define PROJEKT_H

#include <QtWidgets/QMainWindow>
#include "DatabaseConnection.h"
#include "ui_projekt.h"
#include "Person.h"
struct IntelligentPTR
{

	IntelligentPTR() = delete;
	IntelligentPTR(QMainWindow* q)
	{
		this->main = q;
		currentPage = new QWidget();
	}
	~IntelligentPTR()
	{
		delete currentPage;
	}
	void setPage(QWidget * page)
	{
		if (page != NULL) {
			delete currentPage;
			currentPage = page;
			main->setCentralWidget(currentPage);
		}
	}
private:
	QMainWindow* main;
	QWidget* currentPage;
};


class Projekt : public QMainWindow
{
	Q_OBJECT

public:
	Projekt(QWidget *parent = 0, DatabaseConnection * db = NULL);
	~Projekt();
	Person* getPerson();
	void setPerson(Person*);
	void deletePerson();
	void setLoginScreen();
	void setRegistrationScreen();
	void setAccountViewScreen();
	void setMainScreen();
	void setInfoScreen();
	void setPasswordChangeScreen();
private:
	Ui::ProjektClass ui;
	DatabaseConnection* db;
	Person* user;
	IntelligentPTR* pageController;
};

#endif // PROJEKT_H
