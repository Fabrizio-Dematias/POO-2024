#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

AdminDB* AdminDB::m_instance = nullptr;

AdminDB* AdminDB::instance()
{
    if (!m_instance)
        m_instance = new AdminDB();
    return m_instance;
}

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
}

void AdminDB::setDatabasePath(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qCritical() << "Error opening database: " << m_db.lastError().text();
    }
}

QString AdminDB::hashPassword(const QString &password)
{
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
    return QString(hashedPassword.toHex());
}

bool AdminDB::validateUser(const QString &username, const QString &password)
{
    QString hashedPassword = hashPassword(password);
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE username = :username AND password = :password");
    query.bindValue(":username", QVariant(username));
    query.bindValue(":password", QVariant(hashedPassword));

    if (!query.exec())
    {
        qCritical() << "Query execution error: " << query.lastError().text();
        return false;
    }

    return query.next();
}
