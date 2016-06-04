#pragma once
#include <QWidget>
#include <qmainwindow.h>
#include "ui_accountview.h"

class AccountView : public QWidget {
	Q_OBJECT

public:
	AccountView(QMainWindow * parent = Q_NULLPTR);
	~AccountView();

private:
	Ui::AccountView ui;
};
