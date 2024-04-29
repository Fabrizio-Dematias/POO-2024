#include "login.h"
#include <QGridLayout>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent)
{
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
    pbValidar = new QPushButton("Validar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 0, 1, 2);

    setLayout(layout);

    connect(pbValidar, SIGNAL(pressed()), this, SLOT(slot_ValidarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_ValidarUsuario()));
}

Login::~Login()
{
}

void Login::slot_ValidarUsuario()
{
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    if (usuario == "admin" && clave == "1234")
    {
        qDebug() << "Usuario valido";
    }
    else
    {
        qDebug() << "Usuario invalido";
    }
}
