#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void slot_ValidarUsuario();

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbValidar;
};

#endif // LOGIN_H
