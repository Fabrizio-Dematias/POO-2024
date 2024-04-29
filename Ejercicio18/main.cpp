#include <QApplication>
#include "login.h"
#include "ventana.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    Ventana ventana;

    QObject::connect(&login, &Login::loginSuccess, [&]() {
        login.hide();
        ventana.show();
    });

    login.show();

    return a.exec();
}
