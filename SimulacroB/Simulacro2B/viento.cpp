#include "Viento.h"
#include <QDebug>

Viento::Viento(const QString &marca, double precio, const QString &metalUsado)
    : Instrumento(marca, precio), metalUsado(metalUsado)
{
}

void Viento::afinar() const
{
    qDebug() << "Afinando instrumento de viento";
}

QString Viento::getDescripcion() const
{
    return QString("Viento: %1, Precio: %2, Metal: %3").arg(marca).arg(precio).arg(metalUsado);
}
