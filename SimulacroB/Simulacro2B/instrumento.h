#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>

class Instrumento
{
public:
    Instrumento(const QString &marca, double precio);
    virtual ~Instrumento() = default;
    virtual void afinar() const = 0;
    virtual QString getDescripcion() const = 0;

protected:
    QString marca;
    double precio;
};

#endif // INSTRUMENTO_H
