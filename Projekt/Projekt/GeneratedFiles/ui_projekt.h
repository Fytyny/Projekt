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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QMenuBar *menuBar;
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
        ProjektClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjektClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 21));
        ProjektClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjektClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjektClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjektClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjektClass->setStatusBar(statusBar);

        retranslateUi(ProjektClass);

        QMetaObject::connectSlotsByName(ProjektClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjektClass)
    {
        ProjektClass->setWindowTitle(QApplication::translate("ProjektClass", "Projekt", 0));
        actionSdad->setText(QApplication::translate("ProjektClass", "sdad", 0));
        actionAsfasf->setText(QApplication::translate("ProjektClass", "asfasf", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjektClass: public Ui_ProjektClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJEKT_H
