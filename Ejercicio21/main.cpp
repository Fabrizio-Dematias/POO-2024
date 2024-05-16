#include <QApplication>
#include "login.h"
#include "ventana.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Ventana *ventana = new Ventana();
    Login *login = new Login();
    login->show();

    int retCode = app.exec();

    delete login;
    delete ventana;

    return retCode;
}
