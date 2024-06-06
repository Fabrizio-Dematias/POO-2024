#ifndef GUITARRA_H
#define GUITARRA_H

#include "Instrumento.h"

class Guitarra : public Instrumento
{
public:
    Guitarra(const QString &marca, double precio, int cantidadCuerdas);
    void afinar() const override;
    QString getDescripcion() const override;

private:
    int cantidadCuerdas;
};

#endif // GUITARRA_H
