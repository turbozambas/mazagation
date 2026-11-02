#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // inicializar vars
    int n[3], maior;
    float soma=0, media;

    // ciclo a pedir e a somar 3 números
    for (int i=0; i<3; i++) {
        cout << "Inserir um número: ";
        cin >> n[i];
        cout << n[i] << "\n";
        soma+=n[i]; // soma

        // maior
        if (i==0) { maior = n[i]; }
        else if (n[i]>maior) { maior = n[i]; }
    }
    
    // cálculo da média dos 3 números
    media = soma/3;
    
    // apresentação dos resultados
    cout << "Soma: " << soma << "\nMaior: " << maior << "\nMédia: " << media << "\n";
    return 0;
}