#include "login.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

Login::Login(QWidget *parent) : QDialog(parent)
{
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *loginButton = new QPushButton("Login", this);
    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    setLayout(layout);
}

Login::~Login()
{
}

void Login::attemptLogin()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username == "admin" && password == "1234") {
        emit loginSuccess();
        accept();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}
