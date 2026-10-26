#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

int main() {
    srand(time(NULL));
    int n1, n2, i=1, resposta;
    do {
        n1=rand() % 10;
        n2=rand() % 10;
        cout << i << ": " << n1 << "x" << n2 << "? ";
        cin >> resposta;
        if (resposta==n1*n2) { i++; }
        else { i=i-2; }
        if (i==4) { cout << "YOU WIN!"; }
    } while (i<=3);
}