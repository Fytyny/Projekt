#ifndef PROJEKT_H
#define PROJEKT_H

#include <QtWidgets/QMainWindow>
#include "DatabaseConnection.h"
#include "ui_projekt.h"

class Projekt : public QMainWindow
{
	Q_OBJECT

public:
	Projekt(QWidget *parent = 0, DatabaseConnection * db = NULL);
	~Projekt();

private:
	Ui::ProjektClass ui;
};

#endif // PROJEKT_H
