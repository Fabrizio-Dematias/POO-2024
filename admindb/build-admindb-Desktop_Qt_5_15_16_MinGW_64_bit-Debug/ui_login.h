/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QLabel *lUsuario;
    QLineEdit *leUsuario;
    QLabel *lClave;
    QLineEdit *leClave;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(436, 134);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lUsuario = new QLabel(Login);
        lUsuario->setObjectName(QString::fromUtf8("lUsuario"));

        gridLayout->addWidget(lUsuario, 0, 0, 1, 1);

        leUsuario = new QLineEdit(Login);
        leUsuario->setObjectName(QString::fromUtf8("leUsuario"));

        gridLayout->addWidget(leUsuario, 0, 1, 1, 1);

        lClave = new QLabel(Login);
        lClave->setObjectName(QString::fromUtf8("lClave"));

        gridLayout->addWidget(lClave, 1, 0, 1, 1);

        leClave = new QLineEdit(Login);
        leClave->setObjectName(QString::fromUtf8("leClave"));
        leClave->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leClave, 1, 1, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        lUsuario->setText(QCoreApplication::translate("Login", "Usuario", nullptr));
        lClave->setText(QCoreApplication::translate("Login", "Clave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
