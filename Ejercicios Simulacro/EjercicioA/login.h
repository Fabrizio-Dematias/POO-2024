#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void loginSuccessful();

private slots:
    void attemptLogin();

private:
    QLineEdit *dniEdit;
    QLineEdit *claveEdit;
    QLabel *messageLabel;
    int loginAttempts;
};

#endif // LOGIN_H
