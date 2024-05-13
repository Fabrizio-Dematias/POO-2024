#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QCryptographicHash> // Necesario para utilizar MD5

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite)
{
    db.setDatabaseName(archivoSqlite);

    if (db.open())
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    if (db.open()) {
        QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5);
        QString claveMd5 = QString(hash.toHex());

        QSqlQuery query = db.exec("SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                  usuario + "' AND clave = '" + claveMd5 + "'");

        while (query.next()) {
            qDebug() << query.value(0).toString() << " " << query.value(1).toString();
            return true;
        }
    }

    return false;
}
