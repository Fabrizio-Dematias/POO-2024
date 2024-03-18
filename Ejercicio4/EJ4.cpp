#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int randomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {

    srand(time(0));

    vector<int> valores;

    for (int i = 0; i < 30; ++i) {
        valores.push_back(randomNumber(1, 15));
    }

    sort(valores.begin(), valores.end());
    int moda = valores[0];
    int modaCount = 1;
    int current = valores[0];
    int currentCount = 1;

    for (size_t i = 1; i < valores.size(); ++i) {
        if (valores[i] == current) {
            ++currentCount;
        } else {
            if (currentCount > modaCount) {
                moda = current;
                modaCount = currentCount;
            }
            current = valores[i];
            currentCount = 1;
        }
    }

    if (currentCount > modaCount) {
        moda = current;
        modaCount = currentCount;
    }

    cout << "La moda es: " << moda << " aparece " << modaCount << " veces." << endl;

    return 0;
}
