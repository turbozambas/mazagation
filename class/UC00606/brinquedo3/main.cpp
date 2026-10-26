#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

int main() {
    srand(time(NULL));
    int r=rand() % 101, resposta, contador=0;

    do {
        cout << "Adivinhe o número: ";
        cin >> resposta;

        if (resposta>r) {
            cout << "Vai pra baixo\n";
        } else if (resposta<r) {
            cout << "Vai pra cima\n";
        } else {
            cout << "Acertou em " << contador << " tentativas.\n";
        }
        contador++;
    } while (resposta!=r);

    return 0;
}