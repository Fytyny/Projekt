/********************************************************************************
** Form generated from reading UI file 'MoneyExchange.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONEYEXCHANGE_H
#define UI_MONEYEXCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoneyExchange
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *accNum;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *amountOfMoney;
    QComboBox *comboBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *MoneyExchange)
    {
        if (MoneyExchange->objectName().isEmpty())
            MoneyExchange->setObjectName(QStringLiteral("MoneyExchange"));
        MoneyExchange->resize(609, 394);
        widget = new QWidget(MoneyExchange);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 140, 309, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        accNum = new QLineEdit(widget);
        accNum->setObjectName(QStringLiteral("accNum"));

        horizontalLayout->addWidget(accNum);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        amountOfMoney = new QLineEdit(widget);
        amountOfMoney->setObjectName(QStringLiteral("amountOfMoney"));
        amountOfMoney->setInputMethodHints(Qt::ImhDigitsOnly);

        horizontalLayout_2->addWidget(amountOfMoney);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1 = new QWidget(MoneyExchange);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(220, 260, 158, 25));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        retranslateUi(MoneyExchange);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MoneyExchange, SLOT(goBack()));
        QObject::connect(pushButton, SIGNAL(clicked()), MoneyExchange, SLOT(sendMoney()));

        QMetaObject::connectSlotsByName(MoneyExchange);
    } // setupUi

    void retranslateUi(QWidget *MoneyExchange)
    {
        MoneyExchange->setWindowTitle(QApplication::translate("MoneyExchange", "MoneyExchange", 0));
        label->setText(QApplication::translate("MoneyExchange", "Account number:  ", 0));
        label_2->setText(QApplication::translate("MoneyExchange", "Amount of money:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MoneyExchange", "PLN", 0)
         << QApplication::translate("MoneyExchange", "USD", 0)
         << QApplication::translate("MoneyExchange", "EUR", 0)
        );
        pushButton_2->setText(QApplication::translate("MoneyExchange", "Back", 0));
        pushButton->setText(QApplication::translate("MoneyExchange", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class MoneyExchange: public Ui_MoneyExchange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONEYEXCHANGE_H
