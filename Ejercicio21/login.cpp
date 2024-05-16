#include "login.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "ventana.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Username");
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);

    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginButtonClicked);

    // Configurar la base de datos SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/fabri/OneDrive/Escritorio/users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Database connection failed.");
    }
}

void Login::onLoginButtonClicked() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (validateCredentials(username, password)) {
        Ventana *ventana = new Ventana();
        ventana->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

bool Login::validateCredentials(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}
