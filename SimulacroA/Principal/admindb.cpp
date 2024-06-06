#include "admindb.h"

AdminDB* AdminDB::instance = nullptr;

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    // Constructor privado
}

AdminDB::~AdminDB()
{
    if (db.isOpen()) {
        db.close();
    }
}

AdminDB* AdminDB::getInstance()
{
    if (instance == nullptr) {
        instance = new AdminDB();
    }
    return instance;
}

bool AdminDB::connectToDatabase(const QString &dbPath)
{
    db = QSqlDatabase::addDatabase("QSQLITE"); // Usamos SQLite
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error: Unable to connect to database:" << db.lastError().text();
        return false;
    }

    return true;
}

QSqlQuery AdminDB::executeQuery(const QString &query)
{
    QSqlQuery q;
    if (!q.exec(query)) {
        qDebug() << "Error: Unable to execute query:" << q.lastError().text();
    }
    return q;
}
