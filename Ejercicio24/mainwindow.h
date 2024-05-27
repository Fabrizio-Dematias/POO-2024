#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFileDialog>
#include <QPainter>
#include <QImage>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDownloadButtonClicked();
    void onSelectDirButtonClicked();
    void onSelectImageButtonClicked();
    void onHtmlDownloaded(QNetworkReply* reply);
    void paintEvent(QPaintEvent* event);

private:
    QNetworkAccessManager *manager;
    QString downloadDirectory;
    QImage selectedImage;

    QLineEdit *urlLineEdit;
    QPushButton *downloadButton;
    QPushButton *selectDirButton;
    QPushButton *selectImageButton;
    QLabel *directoryLabel;
};

#endif // MAINWINDOW_H
