#include <QApplication>
#include "ventana.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Ventana ventana;
    ventana.resize(400, 300);
    ventana.show();

    return app.exec();
}
