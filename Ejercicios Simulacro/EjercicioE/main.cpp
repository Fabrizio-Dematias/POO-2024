#include <QApplication>
#include "ventana.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear una instancia de la ventana principal
    Ventana ventana;
    ventana.setWindowTitle("Bola 8");
    ventana.show();

    // Ejecutar la aplicación
    return a.exec();
}
