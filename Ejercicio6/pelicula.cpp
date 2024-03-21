#include "pelicula.h"
#include <iostream>
#include <QCoreApplication>

using namespace std;

Pelicula::Pelicula() {
    m_titulo = "";
    m_director = "";
    m_duracion = 0;
}

Pelicula::Pelicula(QString titulo, QString director, int duracion) {
    m_titulo = titulo;
    m_director = director;
    m_duracion = duracion;
}

void Pelicula::setTitulo(QString titulo) {
    m_titulo = titulo;
}

QString Pelicula::getTitulo() const {
    return m_titulo;
}

void Pelicula::setDirector(QString director) {
    m_director = director;
}

QString Pelicula::getDirector() const {
    return m_director;
}

void Pelicula::setDuracion(int duracion) {
    m_duracion = duracion;
}

int Pelicula::getDuracion() const {
    return m_duracion;
}

void Pelicula::mostrarInfo() const {
    cout << "Titulo: " << m_titulo.toStdString() << endl;
    cout << "Director: " << m_director.toStdString() << endl;
    cout << "Duracion: " << m_duracion << " minutos" << endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Crear objetos de la clase Pelicula
    Pelicula pelicula1("Rapidos y Furiosos 9", "Justin Lin", 223);
    Pelicula pelicula2("Avatar 2", "James Cameron", 312);

    // Mostrar información de las películas
    pelicula1.mostrarInfo();
    std::cout << std::endl;
    pelicula2.mostrarInfo();

    return a.exec();
}
