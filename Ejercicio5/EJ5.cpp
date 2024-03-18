#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    vector<string> expresiones;

    expresiones.push_back("Hola a todos");
    expresiones.push_back("Esto es programacion orientada a objetos");
    expresiones.push_back("Mejor tarde que nunca");
    expresiones.push_back("Estamos en el 2024");


    sort(expresiones.begin(), expresiones.end());

    cout << "Expresiones idiomaticas ordenadas alfabeticamente:" << endl;
    for (const auto& expresion : expresiones) {
        cout << expresion << endl;
    }

    return 0;
}
