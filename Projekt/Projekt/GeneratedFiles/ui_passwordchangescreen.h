/********************************************************************************
** Form generated from reading UI file 'passwordchangescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDCHANGESCREEN_H
#define UI_PASSWORDCHANGESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordChangeScreen
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *newPassword;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *confirmNewPassword;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PasswordChangeScreen)
    {
        if (PasswordChangeScreen->objectName().isEmpty())
            PasswordChangeScreen->setObjectName(QStringLiteral("PasswordChangeScreen"));
        PasswordChangeScreen->resize(759, 507);
        verticalLayoutWidget = new QWidget(PasswordChangeScreen);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(180, 150, 360, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        password = new QLineEdit(verticalLayoutWidget);
        password->setObjectName(QStringLiteral("password"));

        horizontalLayout->addWidget(password);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        newPassword = new QLineEdit(verticalLayoutWidget);
        newPassword->setObjectName(QStringLiteral("newPassword"));
        newPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(newPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        confirmNewPassword = new QLineEdit(verticalLayoutWidget);
        confirmNewPassword->setObjectName(QStringLiteral("confirmNewPassword"));
        confirmNewPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(confirmNewPassword);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        widget = new QWidget(PasswordChangeScreen);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(270, 310, 158, 25));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        label->raise();
        password->raise();
        label_2->raise();
        newPassword->raise();
        label_3->raise();
        confirmNewPassword->raise();
        pushButton->raise();
        pushButton_2->raise();
        verticalLayoutWidget->raise();
        pushButton_2->raise();

        retranslateUi(PasswordChangeScreen);
        QObject::connect(pushButton, SIGNAL(clicked()), PasswordChangeScreen, SLOT(goBack()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), PasswordChangeScreen, SLOT(updatePassword()));

        QMetaObject::connectSlotsByName(PasswordChangeScreen);
    } // setupUi

    void retranslateUi(QWidget *PasswordChangeScreen)
    {
        PasswordChangeScreen->setWindowTitle(QApplication::translate("PasswordChangeScreen", "PasswordChangeScreen", 0));
        label->setText(QApplication::translate("PasswordChangeScreen", "Password:                     ", 0));
        label_2->setText(QApplication::translate("PasswordChangeScreen", "New password:             ", 0));
        label_3->setText(QApplication::translate("PasswordChangeScreen", "Confirm new password:", 0));
        pushButton->setText(QApplication::translate("PasswordChangeScreen", "Back", 0));
        pushButton_2->setText(QApplication::translate("PasswordChangeScreen", "Update", 0));
    } // retranslateUi

};

namespace Ui {
    class PasswordChangeScreen: public Ui_PasswordChangeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCHANGESCREEN_H
