#ifndef PELICULA_H
#define PELICULA_H

#include <QString>

class Pelicula
{
public:
    Pelicula();
    Pelicula(QString titulo, QString director, int duracion);

    QString getTitulo() const;
    void setTitulo(const QString &value);

    QString getDirector() const;
    void setDirector(const QString &value);

    int getDuracion() const;
    void setDuracion(int value);

private:
    QString titulo;
    QString director;
    int duracion;
};

#endif // PELICULA_H
