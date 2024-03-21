#include <iostream>

    class Poste {
private:
    double altura;
    double diametro;

public:
    Poste(double altura, double diametro) : altura(altura), diametro(diametro) {}

    double getAltura() const {
        return altura;
    }

    double getDiametro() const {
        return diametro;
    }
};

void imprimirDescripcion(const Poste& poste) {
    std::cout << "Descripcion: Poste con altura de " << poste.getAltura() << " metros y " << poste.getDiametro() << " cm de diametro" << std::endl;
}

int main() {
    Poste poste1(8, 15);
    Poste poste2(10, 20);

    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);

    return 0;
}

