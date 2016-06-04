/********************************************************************************
** Form generated from reading UI file 'accountview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTVIEW_H
#define UI_ACCOUNTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountView
{
public:

    void setupUi(QWidget *AccountView)
    {
        if (AccountView->objectName().isEmpty())
            AccountView->setObjectName(QStringLiteral("AccountView"));
        AccountView->resize(400, 300);

        retranslateUi(AccountView);

        QMetaObject::connectSlotsByName(AccountView);
    } // setupUi

    void retranslateUi(QWidget *AccountView)
    {
        AccountView->setWindowTitle(QApplication::translate("AccountView", "AccountView", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountView: public Ui_AccountView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTVIEW_H
