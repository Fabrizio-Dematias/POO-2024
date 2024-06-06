#include "Teclado.h"
#include <QDebug>

Teclado::Teclado(const QString &marca, double precio, int cantidadTeclas)
    : Instrumento(marca, precio), cantidadTeclas(cantidadTeclas)
{
}

void Teclado::afinar() const
{
    qDebug() << "Afinando teclado";
}

QString Teclado::getDescripcion() const
{
    return QString("Teclado: %1, Precio: %2, Teclas: %3").arg(marca).arg(precio).arg(cantidadTeclas);
}
