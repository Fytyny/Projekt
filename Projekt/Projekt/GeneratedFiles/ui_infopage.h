/********************************************************************************
** Form generated from reading UI file 'infopage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOPAGE_H
#define UI_INFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infoPage
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *firstName;
    QLabel *LastName;
    QComboBox *comboBox;
    QLabel *SecondName;
    QLabel *label_2;
    QLabel *accNumber;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *infoPage)
    {
        if (infoPage->objectName().isEmpty())
            infoPage->setObjectName(QStringLiteral("infoPage"));
        infoPage->resize(581, 401);
        verticalLayout_4 = new QVBoxLayout(infoPage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(infoPage);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        firstName = new QLabel(infoPage);
        firstName->setObjectName(QStringLiteral("firstName"));
        QFont font1;
        font1.setPointSize(14);
        firstName->setFont(font1);

        horizontalLayout->addWidget(firstName);

        LastName = new QLabel(infoPage);
        LastName->setObjectName(QStringLiteral("LastName"));
        LastName->setFont(font1);

        horizontalLayout->addWidget(LastName);

        comboBox = new QComboBox(infoPage);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        SecondName = new QLabel(infoPage);
        SecondName->setObjectName(QStringLiteral("SecondName"));
        SecondName->setFont(font1);

        verticalLayout->addWidget(SecondName);


        verticalLayout_2->addLayout(verticalLayout);

        label_2 = new QLabel(infoPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        accNumber = new QLabel(infoPage);
        accNumber->setObjectName(QStringLiteral("accNumber"));
        QFont font2;
        font2.setPointSize(28);
        accNumber->setFont(font2);

        verticalLayout_2->addWidget(accNumber);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(infoPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(infoPage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(infoPage);
        QObject::connect(pushButton_2, SIGNAL(clicked()), infoPage, SLOT(passwordChange()));
        QObject::connect(pushButton, SIGNAL(clicked()), infoPage, SLOT(goBack()));
        QObject::connect(comboBox, SIGNAL(activated(QString)), infoPage, SLOT(changeType()));

        QMetaObject::connectSlotsByName(infoPage);
    } // setupUi

    void retranslateUi(QWidget *infoPage)
    {
        infoPage->setWindowTitle(QApplication::translate("infoPage", "infoPage", 0));
        label->setText(QApplication::translate("infoPage", "Your data:", 0));
        firstName->setText(QApplication::translate("infoPage", "FirstName", 0));
        LastName->setText(QApplication::translate("infoPage", "LastName", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("infoPage", "PLN", 0)
         << QApplication::translate("infoPage", "USD", 0)
         << QApplication::translate("infoPage", "EUR", 0)
        );
        SecondName->setText(QApplication::translate("infoPage", "SecondName", 0));
        label_2->setText(QApplication::translate("infoPage", "Your Account Number is:", 0));
        accNumber->setText(QApplication::translate("infoPage", "14214142141421", 0));
        pushButton->setText(QApplication::translate("infoPage", "Back", 0));
        pushButton_2->setText(QApplication::translate("infoPage", "Change Password", 0));
    } // retranslateUi

};

namespace Ui {
    class infoPage: public Ui_infoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOPAGE_H
