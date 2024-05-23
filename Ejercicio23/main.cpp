#include <iostream>
#include <string>
#include <vector>

class EntidadMusical {
public:
    virtual void sonar() const = 0;
    virtual ~EntidadMusical() {}
};

class Instrumento {
public:
    virtual void sonar() const = 0;
    virtual ~Instrumento() {}
};

class Guitarra : public EntidadMusical, public Instrumento {
private:
    int cuerdas;

public:
    Guitarra(int _cuerdas = 6) : cuerdas(_cuerdas) {}

    void sonar() const override {
        std::cout << "Guitarra suena..." << std::endl;
    }

    int getCuerdas() const { return cuerdas; }
    void setCuerdas(int _cuerdas) { cuerdas = _cuerdas; }
};

class Bateria : public EntidadMusical, public Instrumento {
private:
    int tambores;

public:
    Bateria(int _tambores = 5) : tambores(_tambores) {}

    void sonar() const override {
        std::cout << "Bateria suena..." << std::endl;
    }

    int getTambores() const { return tambores; }
    void setTambores(int _tambores) { tambores = _tambores; }
};

class Teclado : public EntidadMusical, public Instrumento {
private:
    int teclas;

public:
    Teclado(int _teclas = 61) : teclas(_teclas) {}

    void sonar() const override {
        std::cout << "Teclado suena..." << std::endl;
    }

    int getTeclas() const { return teclas; }
    void setTeclas(int _teclas) { teclas = _teclas; }
};

int main() {
    std::vector<EntidadMusical*> entidades;

    entidades.push_back(new Guitarra());
    entidades.push_back(new Bateria());
    entidades.push_back(new Teclado());

    for (const auto& entidad : entidades) {
        entidad->sonar();
        delete entidad;
    }

    return 0;
}
