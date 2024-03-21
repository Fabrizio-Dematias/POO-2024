#include <iostream>

template <class T>
void imprimir(T *v, int cantidad, bool mayor_a_menor) {
    // ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T temp = v[i];
        int j = i - 1;
        if (mayor_a_menor) {
            while (j >= 0 && v[j] < temp) {
                v[j + 1] = v[j];
                j--;
            }
        } else {
            while (j >= 0 && v[j] > temp) {
                v[j + 1] = v[j];
                j--;
            }
        }
        v[j + 1] = temp;
    }

    std::cout << "Array ordenado: ";
    if (mayor_a_menor) {
        for (int i = 0; i < cantidad; ++i) {
            std::cout << v[i] << " ";
        }
    } else {
        for (int i = 0; i < cantidad; ++i) {
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int arrayInt[] = {5, 2, 9, 1, 7};
    float arrayFloat[] = {3.4, 1.2, 5.6, 2.1, 8.9};

    std::cout << "Ordenado de mayor a menor:" << std::endl;
    imprimir(arrayInt, 5, true);
    imprimir(arrayFloat, 5, true);

    std::cout << "Ordenado de menor a mayor:" << std::endl;
    imprimir(arrayInt, 5, false);
    imprimir(arrayFloat, 5, false);

    return 0;
}
