#include "Guitarra.h"
#include <QDebug>

Guitarra::Guitarra(const QString &marca, double precio, int cantidadCuerdas)
    : Instrumento(marca, precio), cantidadCuerdas(cantidadCuerdas)
{
}

void Guitarra::afinar() const
{
    qDebug() << "Afinando guitarra";
}

QString Guitarra::getDescripcion() const
{
    return QString("Guitarra: %1, Precio: %2, Cuerdas: %3").arg(marca).arg(precio).arg(cantidadCuerdas);
}
