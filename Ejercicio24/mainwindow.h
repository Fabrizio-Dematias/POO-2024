#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include "htmlparser.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void downloadResources();
    void chooseFile();

private:
    QLineEdit *urlLineEdit;
    HtmlParser *parser;
    QNetworkAccessManager *networkManager;
    QString selectedImagePath;
};

#endif // MAINWINDOW_H
