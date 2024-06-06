#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QSqlQuery>
#include "adminDB.h"
#include "linea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    QList<Linea*> lineas; // Lista para almacenar todas las líneas de la base de datos
};

#endif // PRINCIPAL_H
