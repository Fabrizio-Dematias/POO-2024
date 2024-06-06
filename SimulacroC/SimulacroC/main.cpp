#include <QApplication>
#include "manager.h"
#include "admindb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ruta de la base de datos
    QString dbPath = "C:/Users/fabri/OneDrive/Escritorio/baseusers.sqlite";
    AdminDB::instance()->setDatabasePath(dbPath);

    // Registrar un usuario para pruebas (opcional)
    // AdminDB::instance()->registerUser("admin", "password");

    Manager::instance()->showLogin();

    return a.exec();
}
