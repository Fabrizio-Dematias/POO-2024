#include <QApplication>
#include "login.h"
#include "home.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Crear instancias de LoginWidget y Home
    LoginWidget loginWidget;
    Home home("C:/Users/fabri/OneDrive/Escritorio/logo.png");

    QObject::connect(&loginWidget, &LoginWidget::loginSuccessful, &home, &Home::showHomeWindow);

    loginWidget.show();

    return a.exec();
}
