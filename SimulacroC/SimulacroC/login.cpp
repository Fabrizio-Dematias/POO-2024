#include "login.h"
#include "ui_login.h"
#include "admindb.h"
#include "manager.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (AdminDB::instance()->validateUser(username, password))
    {
        QMessageBox::information(this, "Login", "Login successful");
        // Show a new empty window
        QWidget *emptyWindow = new QWidget();
        emptyWindow->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid username or password");
    }
}
