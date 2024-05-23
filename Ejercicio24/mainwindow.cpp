#include "mainwindow.h"
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), urlLineEdit(new QLineEdit(this)), parser(new HtmlParser(this)), networkManager(new QNetworkAccessManager(this))
{
    QPushButton *downloadButton = new QPushButton("Descargar", this);
    QPushButton *chooseFileButton = new QPushButton("Seleccionar Archivo", this);

    connect(downloadButton, &QPushButton::clicked, this, &MainWindow::downloadResources);
    connect(chooseFileButton, &QPushButton::clicked, this, &MainWindow::chooseFile);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(urlLineEdit);
    layout->addWidget(downloadButton);
    layout->addWidget(chooseFileButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::downloadResources()
{
    QString url = urlLineEdit->text();
    QNetworkRequest request(QUrl(url));
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString html = reply->readAll();
            QStringList resources = parser->parseHtml(html);
            QString directory = QFileDialog::getExistingDirectory(this, "Seleccionar Directorio");
            if (!directory.isEmpty()) {
                for (const QString &resourceUrl : resources) {
                    QNetworkRequest resourceRequest(QUrl(resourceUrl));
                    QNetworkReply *resourceReply = networkManager->get(resourceRequest);
                    connect(resourceReply, &QNetworkReply::finished, this, [this, resourceReply, directory]() {
                        if (resourceReply->error() == QNetworkReply::NoError) {
                            QString fileName = QFileInfo(QUrl(resourceReply->url().toString()).path()).fileName();
                            QFile file(directory + "/" + fileName);
                            if (file.open(QIODevice::WriteOnly)) {
                                file.write(resourceReply->readAll());
                                file.close();
                            }
                        }
                        resourceReply->deleteLater();
                    });
                }
            }
        }
        reply->deleteLater();
    });
}

void MainWindow::chooseFile()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Seleccionar Imagen"), QDir::homePath(), tr("Imagen (*.png *.jpg *.jpeg)"));
    if (!imagePath.isEmpty()) {
        selectedImagePath = imagePath;
        update();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    if (!selectedImagePath.isEmpty()) {
        QPainter painter(this);
        QPixmap pixmap(selectedImagePath);
        painter.drawPixmap(10, 10, pixmap.scaled(width() - 20, height() - 20, Qt::KeepAspectRatio));
    }
}
