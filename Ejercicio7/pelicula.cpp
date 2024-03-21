#include "pelicula.h"
#include <QApplicationStateChangeEvent>


Pelicula::Pelicula()
{
}

Pelicula::Pelicula(QString titulo, QString director, int duracion)
    : titulo(titulo), director(director), duracion(duracion)
{
    // Constructor con parametros
}

QString Pelicula::getTitulo() const
{
    return titulo;
}

void Pelicula::setTitulo(const QString &value)
{
    titulo = value;
}

QString Pelicula::getDirector() const
{
    return director;
}

void Pelicula::setDirector(const QString &value)
{
    director = value;
}

int Pelicula::getDuracion() const
{
    return duracion;
}

void Pelicula::setDuracion(int value)
{
    duracion = value;
}

