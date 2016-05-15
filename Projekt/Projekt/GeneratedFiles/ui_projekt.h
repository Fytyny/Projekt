/********************************************************************************
** Form generated from reading UI file 'projekt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJEKT_H
#define UI_PROJEKT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjektClass
{
public:
    QAction *actionSdad;
    QAction *actionAsfasf;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuSdad;
    QMenu *menuFsfs;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjektClass)
    {
        if (ProjektClass->objectName().isEmpty())
            ProjektClass->setObjectName(QStringLiteral("ProjektClass"));
        ProjektClass->resize(612, 413);
        actionSdad = new QAction(ProjektClass);
        actionSdad->setObjectName(QStringLiteral("actionSdad"));
        actionAsfasf = new QAction(ProjektClass);
        actionAsfasf->setObjectName(QStringLiteral("actionAsfasf"));
        centralWidget = new QWidget(ProjektClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 140, 113, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 180, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 220, 75, 23));
        ProjektClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjektClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 21));
        menuSdad = new QMenu(menuBar);
        menuSdad->setObjectName(QStringLiteral("menuSdad"));
        menuFsfs = new QMenu(menuBar);
        menuFsfs->setObjectName(QStringLiteral("menuFsfs"));
        ProjektClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjektClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjektClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjektClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjektClass->setStatusBar(statusBar);

        menuBar->addAction(menuSdad->menuAction());
        menuBar->addAction(menuFsfs->menuAction());
        menuSdad->addAction(actionAsfasf);
        menuFsfs->addAction(actionSdad);

        retranslateUi(ProjektClass);
        QObject::connect(pushButton, SIGNAL(clicked()), ProjektClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ProjektClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjektClass)
    {
        ProjektClass->setWindowTitle(QApplication::translate("ProjektClass", "Projekt", 0));
        actionSdad->setText(QApplication::translate("ProjektClass", "sdad", 0));
        actionAsfasf->setText(QApplication::translate("ProjektClass", "asfasf", 0));
        pushButton->setText(QApplication::translate("ProjektClass", "PushButton", 0));
        menuSdad->setTitle(QApplication::translate("ProjektClass", "sdad", 0));
        menuFsfs->setTitle(QApplication::translate("ProjektClass", "fsfs", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjektClass: public Ui_ProjektClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJEKT_H
