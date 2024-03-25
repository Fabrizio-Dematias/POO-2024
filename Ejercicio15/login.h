#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

// Agrega la declaración de Formulario solo si es necesario
class Formulario;

class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

private slots:
    void verificarLogin();
    void abrirFormulario();
    void mostrarMensajeInicioSesionExitoso();

private:
    QLabel *lbl_usuario;
    QLabel *lbl_contrasena;
    QLabel *lbl_captcha;
    QString captcha_value;

    QLineEdit *txt_usuario;
    QLineEdit *txt_contrasena;
    QLineEdit *txt_captcha;

    QPushButton *btn_login;

    Formulario *formulario; // Agrega la declaración de Formulario solo si es necesario
};

#endif // LOGIN_H
