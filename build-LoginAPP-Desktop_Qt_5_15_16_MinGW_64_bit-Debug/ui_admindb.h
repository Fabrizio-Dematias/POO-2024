/********************************************************************************
** Form generated from reading UI file 'admindb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDB_H
#define UI_ADMINDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminDB
{
public:

    void setupUi(QWidget *AdminDB)
    {
        if (AdminDB->objectName().isEmpty())
            AdminDB->setObjectName(QString::fromUtf8("AdminDB"));
        AdminDB->resize(800, 600);

        retranslateUi(AdminDB);

        QMetaObject::connectSlotsByName(AdminDB);
    } // setupUi

    void retranslateUi(QWidget *AdminDB)
    {
        AdminDB->setWindowTitle(QCoreApplication::translate("AdminDB", "AdminDB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDB: public Ui_AdminDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDB_H
