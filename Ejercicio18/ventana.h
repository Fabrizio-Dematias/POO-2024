#ifndef VENTANA_H
#define VENTANA_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QNetworkReply>

class Ventana : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

public slots:
    void displayHTML(const QString &html);
    void fetchHTML();
    void handleNetworkError(QNetworkReply::NetworkError error);

private:
    QTextEdit *htmlTextEdit;
    QLineEdit *urlLineEdit;
};

#endif // VENTANA_H
