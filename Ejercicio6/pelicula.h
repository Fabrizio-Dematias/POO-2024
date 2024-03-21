#ifndef PELICULA_H
#define PELICULA_H

#include <QString>

class Pelicula
{
public:
    Pelicula();
    Pelicula(QString titulo, QString director, int duracion);

    void setTitulo(QString titulo);
    QString getTitulo() const;
    void setDirector(QString director);
    QString getDirector() const;
    void setDuracion(int duracion);
    int getDuracion() const;

    void mostrarInfo() const;

private:
    QString m_titulo;
    QString m_director;
    int m_duracion;
};

#endif // PELICULA_H
