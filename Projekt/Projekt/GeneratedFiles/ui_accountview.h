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
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountView
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *cashAmount;
    QLabel *type;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QCommandLinkButton *commandLinkButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *FirstName;
    QLabel *LastName;

    void setupUi(QWidget *AccountView)
    {
        if (AccountView->objectName().isEmpty())
            AccountView->setObjectName(QStringLiteral("AccountView"));
        AccountView->resize(627, 399);
        horizontalLayoutWidget = new QWidget(AccountView);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(280, 320, 301, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        cashAmount = new QLCDNumber(horizontalLayoutWidget);
        cashAmount->setObjectName(QStringLiteral("cashAmount"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cashAmount->sizePolicy().hasHeightForWidth());
        cashAmount->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(7);
        cashAmount->setFont(font1);
        cashAmount->setInputMethodHints(Qt::ImhNone);
        cashAmount->setFrameShape(QFrame::StyledPanel);
        cashAmount->setLineWidth(7);
        cashAmount->setSmallDecimalPoint(true);
        cashAmount->setDigitCount(12);
        cashAmount->setMode(QLCDNumber::Dec);
        cashAmount->setSegmentStyle(QLCDNumber::Flat);
        cashAmount->setProperty("value", QVariant(0));
        cashAmount->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(cashAmount);

        type = new QLabel(horizontalLayoutWidget);
        type->setObjectName(QStringLiteral("type"));

        horizontalLayout->addWidget(type);

        pushButton = new QPushButton(AccountView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 10, 75, 23));
        pushButton_2 = new QPushButton(AccountView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(550, 10, 31, 21));
        textBrowser = new QTextBrowser(AccountView);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(280, 40, 301, 271));
        commandLinkButton = new QCommandLinkButton(AccountView);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(40, 60, 185, 41));
        layoutWidget = new QWidget(AccountView);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 361, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        FirstName = new QLabel(layoutWidget);
        FirstName->setObjectName(QStringLiteral("FirstName"));
        QFont font2;
        font2.setPointSize(14);
        FirstName->setFont(font2);

        horizontalLayout_2->addWidget(FirstName);

        LastName = new QLabel(layoutWidget);
        LastName->setObjectName(QStringLiteral("LastName"));
        LastName->setFont(font2);

        horizontalLayout_2->addWidget(LastName);


        retranslateUi(AccountView);
        QObject::connect(pushButton, SIGNAL(clicked()), AccountView, SLOT(logOut()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), AccountView, SLOT(showPersonData()));
        QObject::connect(commandLinkButton, SIGNAL(clicked()), AccountView, SLOT(sendMoney()));

        QMetaObject::connectSlotsByName(AccountView);
    } // setupUi

    void retranslateUi(QWidget *AccountView)
    {
        AccountView->setWindowTitle(QApplication::translate("AccountView", "AccountView", 0));
        label->setText(QApplication::translate("AccountView", "Cash:", 0));
        type->setText(QApplication::translate("AccountView", "TYP", 0));
        pushButton->setText(QApplication::translate("AccountView", "Log Out", 0));
        pushButton_2->setText(QApplication::translate("AccountView", "Ja", 0));
        commandLinkButton->setText(QApplication::translate("AccountView", "Send Money", 0));
        FirstName->setText(QApplication::translate("AccountView", "TextLabel", 0));
        LastName->setText(QApplication::translate("AccountView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountView: public Ui_AccountView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTVIEW_H
