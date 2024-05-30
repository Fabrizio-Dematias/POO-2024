#include "mainwindow.h"
#include <QNetworkRequest>
#include <QRegularExpression>
#include <QUrl>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , manager(new QNetworkAccessManager(this))
{
    // Configuración de la ventana principal
    setWindowTitle("Descargador de Recursos HTML");

    // Crear widgets
    urlLineEdit = new QLineEdit(this);
    downloadButton = new QPushButton("Descargar Recursos", this);
    selectDirButton = new QPushButton("Seleccionar Directorio de Descarga", this);
    selectImageButton = new QPushButton("Seleccionar Imagen", this);
    directoryLabel = new QLabel("No se ha seleccionado ningún directorio", this);

    // Crear layout y añadir widgets
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(urlLineEdit);
    layout->addWidget(downloadButton);
    layout->addWidget(selectDirButton);
    layout->addWidget(selectImageButton);
    layout->addWidget(directoryLabel);

    // Crear contenedor central y establecer layout
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Conectar señales y slots
    connect(downloadButton, &QPushButton::clicked, this, &MainWindow::onDownloadButtonClicked);
    connect(selectDirButton, &QPushButton::clicked, this, &MainWindow::onSelectDirButtonClicked);
    connect(selectImageButton, &QPushButton::clicked, this, &MainWindow::onSelectImageButtonClicked);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onHtmlDownloaded);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onDownloadButtonClicked()
{
    QString url = urlLineEdit->text();
    if (url.isEmpty()) {
        qDebug() << "La URL está vacía.";
        return;
    }

    QUrl qurl(url);
    if (!qurl.isValid()) {
        qDebug() << "La URL no es válida:" << url;
        return;
    }

    qDebug() << "Iniciando la solicitud para URL:" << url;

    QNetworkRequest request(qurl);
    manager->get(request);
}

void MainWindow::onSelectDirButtonClicked()
{
    downloadDirectory = QFileDialog::getExistingDirectory(this, tr("Seleccionar Directorio de Descarga"), "");
    if (!downloadDirectory.isEmpty()) {
        directoryLabel->setText(downloadDirectory);
        qDebug() << "Directorio de descarga seleccionado:" << downloadDirectory;
    }
}

void MainWindow::onSelectImageButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Seleccionar Imagen"), "", tr("Imágenes (*.png *.jpg *.bmp)"));
    if (!filePath.isEmpty()) {
        selectedImage.load(filePath);
        qDebug() << "Imagen seleccionada:" << filePath;
        update();
    }
}

void MainWindow::onHtmlDownloaded(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QString html = reply->readAll();
        qDebug() << "HTML descargado con éxito.";

        // Expresiones regulares para encontrar imágenes, CSS y JavaScript
        QRegularExpression imgRe("<img[^>]+src=[\"']?([^\"'>]+)[\"']?");
        QRegularExpression cssRe("<link[^>]+href=[\"']?([^\"'>]+)[\"']?");
        QRegularExpression jsRe("<script[^>]+src=[\"']?([^\"'>]+)[\"']?");

        auto downloadResource = [this](const QString& resourceUrl, const QUrl& baseUrl) {
            QUrl url(resourceUrl);
            if (url.isRelative()) {
                url = baseUrl.resolved(url);
            }

            QNetworkRequest request(url);
            QNetworkReply* reply = manager->get(request);
            connect(reply, &QNetworkReply::finished, [this, reply, resourceUrl]() {
                if (reply->error() == QNetworkReply::NoError) {
                    QByteArray data = reply->readAll();
                    QString fileName = downloadDirectory + "/" + QFileInfo(QUrl(resourceUrl).path()).fileName();
                    QFile file(fileName);
                    if (file.open(QIODevice::WriteOnly)) {
                        file.write(data);
                        file.close();
                        qDebug() << "Recurso descargado y guardado en:" << fileName;
                    } else {
                        qDebug() << "No se pudo abrir el archivo para escribir:" << fileName;
                    }
                } else {
                    qDebug() << "Error al descargar el recurso:" << reply->errorString();
                }
                reply->deleteLater();
            });
        };

        // Descargar imágenes
        QRegularExpressionMatchIterator imgIt = imgRe.globalMatch(html);
        while (imgIt.hasNext()) {
            QRegularExpressionMatch match = imgIt.next();
            QString imgUrl = match.captured(1);
            qDebug() << "Imagen encontrada:" << imgUrl;
            downloadResource(imgUrl, reply->url());
        }

        // Descargar CSS
        QRegularExpressionMatchIterator cssIt = cssRe.globalMatch(html);
        while (cssIt.hasNext()) {
            QRegularExpressionMatch match = cssIt.next();
            QString cssUrl = match.captured(1);
            qDebug() << "CSS encontrado:" << cssUrl;
            downloadResource(cssUrl, reply->url());
        }

        // Descargar JavaScript
        QRegularExpressionMatchIterator jsIt = jsRe.globalMatch(html);
        while (jsIt.hasNext()) {
            QRegularExpressionMatch match = jsIt.next();
            QString jsUrl = match.captured(1);
            qDebug() << "JavaScript encontrado:" << jsUrl;
            downloadResource(jsUrl, reply->url());
        }
    } else {
        qDebug() << "Error al descargar HTML:" << reply->errorString();
    }
    reply->deleteLater();
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    if (!selectedImage.isNull()) {
        painter.drawImage(10, 150, selectedImage);
    }
    QMainWindow::paintEvent(event);
}
