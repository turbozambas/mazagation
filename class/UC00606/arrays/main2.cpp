#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
using namespace std;

// inicializar variaveis globais
int numeros, range[2];

// RNG (cppreference.com/cpp/numeric/random/uniform_int_distribution)
int randomNumber(int x, int y) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(x, y);
    return dist(gen);
}

// função inicial para inputs
void init() {
    cout << "Quantos números pretende gerar? ";
    cin >> numeros;
    cout << "Gerar de (min.): ";
    cin >> range[0];
    cout << "Gerar a (max.): ";
    cin >> range[1];
}

int main()
{
    // inicializar variaveis locais
    init();
    int n[numeros], maiores=0, contadorNegativos=0, contadorPrimos=0;

    // certificar que o input é válido
    while (range[0]>=range[1] || numeros<=0) init();

    // primeiro ciclo - popular o array
    for (int i = 0; i < numeros; i++) {
        n[i] = randomNumber(range[0],range[1]);
    }
    // mais variaveis locais
    double media, soma=0;
    string mensagemNegativos="Não", mensagemPrimos="Não";
    bool primos=true;

    // segundo ciclo - listar os números do array enquanto calcula a soma
    cout << "--------------------";
    cout << "\n" << numeros << " números gerados (" << range[0] << ":" << range[1] << ")\n";
    for (int i=0; i<numeros; i++) {
        if (i<numeros-1) cout << n[i] << ", ";
        else cout << n[i] << ".";
        soma+=n[i]; // soma
        if (n[i]<0) contadorNegativos++; // contador de negativos
    }
    cout << "\n--------------------";
    
    // cálculo da média dos números
    media = soma/numeros;

    // segundo ciclo - maiores e primos
    for (int i=0; i<numeros; i++) {
        primos=true;
        if (n[i]>media) maiores++; // maiores
        
        if (n[i]>=2) {
            for (int j=2; j<=sqrt(n[i]+1); j++) { // raiz de n não funciona visto que a raiz de 3 é menor que 2 e o ciclo avaria, daí o sqrt(n+1)-- A dica do PJ faz todo sentido!
                if (n[i]%j==0) { // basta encontrar um resto zero para concluir que o número não é primo
                    primos = false;
                    break;
                }
            }
        } else primos = false; // qualquer número inferior a 2 não é primo
        if (primos) contadorPrimos++;
    }
    
    // apresentar os resultados
    if (contadorNegativos>0) mensagemNegativos="Sim";
    if (contadorPrimos>0) mensagemPrimos="Sim";
    cout << "\nSoma: " << soma << "\nMédia: " << media << "\nMaiores que a média: " << maiores;
    cout << "\nNegativos? " << mensagemNegativos << ": " << contadorNegativos << "\nPrimos? " << mensagemPrimos << ": " << contadorPrimos << "\n";
    return 0;
}