#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    static AdminDB* getInstance();

    bool connectToDatabase(const QString &dbPath);
    QSqlQuery executeQuery(const QString &query);

private:
    explicit AdminDB(QObject *parent = nullptr);
    ~AdminDB();

    static AdminDB* instance;
    QSqlDatabase db;
};

#endif // ADMINDB_H
