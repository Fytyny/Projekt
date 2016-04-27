#ifndef PROJEKCIK_H
#define PROJEKCIK_H

#include <QtWidgets/QMainWindow>
#include "ui_projekcik.h"

class Projekcik : public QMainWindow
{
	Q_OBJECT

public:
	Projekcik(QWidget *parent = 0);
	~Projekcik();

private:
	Ui::ProjekcikClass ui;
};

#endif // PROJEKCIK_H
