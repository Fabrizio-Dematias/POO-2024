#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    static AdminDB* instance();
    bool validateUser(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
    void setDatabasePath(const QString &path);

private:
    explicit AdminDB(QObject *parent = nullptr);
    static AdminDB* m_instance;
    QSqlDatabase m_db;
};

#endif // ADMINDB_H
