﻿#pragma once
#include <QWidget>
#include "ui_registration.h"

class Registration : public QWidget {
	Q_OBJECT

public:
	Registration(QWidget * parent = Q_NULLPTR);
	~Registration();

private:
	Ui::Registration ui;
};
