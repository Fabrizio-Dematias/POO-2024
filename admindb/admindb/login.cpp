
#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ventana = new Ventana;

    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

    adminDB = new AdminDB( this );
    qDebug() << "La base se abrio bien" << adminDB->conectar( "C:/Users/fabri/OneDrive/Escritorio/db.sqlite" );
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validarUsuario()
{
    QByteArray hash = QCryptographicHash::hash(ui->leClave->text().toUtf8(), QCryptographicHash::Md5);
    QString claveMd5 = QString(hash.toHex());

    if (adminDB->validarUsuario("usuarios", ui->leUsuario->text(), claveMd5)) {
        ventana->show();
        this->close();
    } else {
        this->close();
    }
}


