#ifndef VIENTO_H
#define VIENTO_H

#include "Instrumento.h"

class Viento : public Instrumento
{
public:
    Viento(const QString &marca, double precio, const QString &metalUsado);
    void afinar() const override;
    QString getDescripcion() const override;

private:
    QString metalUsado;
};

#endif // VIENTO_H
