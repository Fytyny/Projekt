/********************************************************************************
** Form generated from reading UI file 'projekcik.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJEKCIK_H
#define UI_PROJEKCIK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjekcikClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjekcikClass)
    {
        if (ProjekcikClass->objectName().isEmpty())
            ProjekcikClass->setObjectName(QStringLiteral("ProjekcikClass"));
        ProjekcikClass->resize(600, 400);
        centralWidget = new QWidget(ProjekcikClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 230, 75, 23));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(230, 240, 25, 19));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 120, 113, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 150, 111, 16));
        ProjekcikClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjekcikClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ProjekcikClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjekcikClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjekcikClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjekcikClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjekcikClass->setStatusBar(statusBar);

        retranslateUi(ProjekcikClass);

        QMetaObject::connectSlotsByName(ProjekcikClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjekcikClass)
    {
        ProjekcikClass->setWindowTitle(QApplication::translate("ProjekcikClass", "Projekcik", 0));
        pushButton->setText(QApplication::translate("ProjekcikClass", "PushButton", 0));
        toolButton->setText(QApplication::translate("ProjekcikClass", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjekcikClass: public Ui_ProjekcikClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJEKCIK_H
