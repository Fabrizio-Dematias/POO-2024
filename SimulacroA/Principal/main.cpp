#include "principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear e iniciar la ventana principal
    Principal w;
    w.show();

    return a.exec();
}
