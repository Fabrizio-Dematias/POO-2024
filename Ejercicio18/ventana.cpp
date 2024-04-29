#include "ventana.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>

Ventana::Ventana(QWidget *parent) : QDialog(parent)
{
    htmlTextEdit = new QTextEdit(this);
    urlLineEdit = new QLineEdit(this);
    QPushButton *fetchButton = new QPushButton("BUSCAR HTML", this);

    connect(fetchButton, SIGNAL(clicked()), this, SLOT(fetchHTML()));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(htmlTextEdit);
    layout->addWidget(urlLineEdit);
    layout->addWidget(fetchButton);

    setLayout(layout);
}

Ventana::~Ventana()
{
}

void Ventana::displayHTML(const QString &html)
{
    htmlTextEdit->setPlainText(html);
}

void Ventana::fetchHTML()
{
    QString url = urlLineEdit->text();

    if (url.isEmpty()) {
        QMessageBox::warning(this, "URL VACIA", "PORFAVOR INGRESE UNA URL.");
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));

    connect(reply, SIGNAL(finished()), this, SLOT(fetchHTML()));

    connect(reply, SIGNAL(finished()), reply, SLOT(deleteLater()));

    connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), this, SLOT(handleNetworkError(QNetworkReply::NetworkError)));
}

void Ventana::handleNetworkError(QNetworkReply::NetworkError error)
{
    QMessageBox::critical(this, "Network Error", "An error occurred while fetching the HTML.");
}
