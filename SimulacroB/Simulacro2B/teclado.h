#ifndef TECLADO_H
#define TECLADO_H

#include "Instrumento.h"

class Teclado : public Instrumento
{
public:
    Teclado(const QString &marca, double precio, int cantidadTeclas);
    void afinar() const override;
    QString getDescripcion() const override;

private:
    int cantidadTeclas;
};

#endif // TECLADO_H
