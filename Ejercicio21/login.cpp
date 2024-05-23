#include "login.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Login::Login(QWidget *parent) : QWidget(parent) {
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &Login::validateLogin);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/fabri/OneDrive/Escritorio/users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
    }
}

Login::~Login() {
    db.close();
}

void Login::validateLogin() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        emit loginSuccessful();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}
