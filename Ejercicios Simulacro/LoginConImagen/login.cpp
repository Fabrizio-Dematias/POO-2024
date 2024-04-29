#include "login.h"
#include "codeeditor.h"
#include <QGridLayout>
#include <QDebug>
#include <QPainter>
#include <QNetworkRequest>

Login::Login(QWidget *parent) : QWidget(parent), imageDownloaded(false)
{
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
    pbValidar = new QPushButton("Validar");
    networkManager = new QNetworkAccessManager(this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0);
    layout->addWidget(leUsuario, 0, 1);
    layout->addWidget(lClave, 1, 0);
    layout->addWidget(leClave, 1, 1);
    layout->addWidget(pbValidar, 2, 0, 1, 2);

    setLayout(layout);

    connect(pbValidar, SIGNAL(pressed()), this, SLOT(slot_ValidarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_ValidarUsuario()));

    QNetworkRequest request(QUrl(""));
    networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(imagenDescargada(QNetworkReply*)));
}

Login::~Login()
{
}

void Login::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (imageDownloaded)
    {
        QPainter painter(this);
        painter.drawImage(0, 0, backgroundImage.scaled(size()));
    }
}

void Login::slot_ValidarUsuario()
{
    QString usuario = leUsuario->text();
    QString clave = leClave->text();

    if (usuario == "admin" && clave == "123")
    {
        qDebug() << "Usuario valido";

        CodeEditor *editor = new CodeEditor;
        editor->show();

        close();
    }
    else
    {
        qDebug() << "Usuario invalido";
    }
}


void Login::imagenDescargada(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray imageData = reply->readAll();
        if (backgroundImage.loadFromData(imageData))
        {
            imageDownloaded = true;
            update();
        }
    }

    reply->deleteLater();
}
