/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QLineEdit *nameLineEdit;
    QLineEdit *emailLineEdit;
    QPushButton *login;
    QPushButton *gameButton;
    QPushButton *rankinglistButton;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QWidget *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName("LoginScreen");
        LoginScreen->resize(883, 593);
        nameLineEdit = new QLineEdit(LoginScreen);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(580, 210, 191, 31));
        emailLineEdit = new QLineEdit(LoginScreen);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(580, 280, 191, 31));
        login = new QPushButton(LoginScreen);
        login->setObjectName("login");
        login->setGeometry(QRect(630, 340, 91, 41));
        gameButton = new QPushButton(LoginScreen);
        gameButton->setObjectName("gameButton");
        gameButton->setGeometry(QRect(630, 400, 91, 41));
        rankinglistButton = new QPushButton(LoginScreen);
        rankinglistButton->setObjectName("rankinglistButton");
        rankinglistButton->setGeometry(QRect(740, 500, 80, 24));
        dateTimeEdit = new QDateTimeEdit(LoginScreen);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(570, 30, 194, 24));

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QWidget *LoginScreen)
    {
        LoginScreen->setWindowTitle(QCoreApplication::translate("LoginScreen", "Form", nullptr));
        login->setText(QCoreApplication::translate("LoginScreen", "\347\231\273\345\275\225/\346\263\250\345\206\214", nullptr));
        gameButton->setText(QCoreApplication::translate("LoginScreen", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        rankinglistButton->setText(QCoreApplication::translate("LoginScreen", "\346\216\222\350\241\214\346\246\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
