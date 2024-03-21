#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jugador {
public:
    Jugador() : velocidad(0), fuerza(0), nombre("sin nombre") {}
    Jugador(int vel, int fuer, const std::string& nom) : velocidad(vel), fuerza(fuer), nombre(nom) {}

    int getVelocidad() const { return velocidad; }
    int getFuerza() const { return fuerza; }
    string getNombre() const { return nombre; }

    void setVelocidad(int vel) { velocidad = vel; }
    void setFuerza(int fuer) { fuerza = fuer; }
    void setNombre(const string& nom) { nombre = nom; }

    ~Jugador() {}

private:
    int velocidad;
    int fuerza;
    string nombre;
};

int main() {
    vector<Jugador> jugadores;

    // se sgregan 10 jugadores diferengtes
    for (int i = 1; i <= 10; ++i) {
        Jugador jugador;
        jugador.setNombre("Jugador" + std::to_string(i));
        jugador.setVelocidad(i * 2);
        jugador.setFuerza(i * 3);
        jugadores.push_back(jugador);
    }

    for (const Jugador& jugador : jugadores) {
        cout << "Nombre: " << jugador.getNombre() << ", Velocidad: " << jugador.getVelocidad()
                  << ", Fuerza: " << jugador.getFuerza() << std::endl;
    }

    return 0;
}
