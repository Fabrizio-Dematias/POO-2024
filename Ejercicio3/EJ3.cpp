#include <iostream>

using namespace std;

namespace MiBiblioteca {

const char* version() {
    return "Version 1.0 - Ultima actualizacion: 18 de marzo de 2024";
}
}

int main() {

    cout << "Informacion de la biblioteca: " << MiBiblioteca::version() << endl;
    return 0;
}
