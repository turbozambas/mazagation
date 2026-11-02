#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // inicializar vars
    int n[10]={4,7,0,1,14,16,99,100,29,12}, maiores=0, nmensagemNegativos=0, nPrimos=0, soma=0, media;
    string mensagemNegativos, mensagemPrimos;
    bool primos=true;

    // ciclo
    for (int i=0; i<10; i++) {
        soma+=n[i]; // soma
        if (n[i]<0) nmensagemNegativos++; // mensagemNegativos
    }
    
    // cálculo da média dos números
    media = soma/10;

    // maiores e primos
    for (int i=0; i<10; i++) {
        primos=true;
        if (n[i]>media) maiores++; // maiores
        
        if (n[i]>=2) {
            for (int j=2; j<=sqrt(n[i]+1); j++) { // raiz de n não funciona visto que a raiz de 3 é menor que 2 e o ciclo avaria, daí o sqrt(n+1)-- A dica do PJ faz todo sentido!
                if (n[i]%j==0) { // basta encontrar um resto zero para concluir que o número não é primo
                    primos = false;
                    break;
                }
            }
        } else { // qualquer número inferior a 2 não é primo
            primos = false;
        }
        if (primos) nPrimos++;
    }
    
    // apresentação dos resultados
    if (nmensagemNegativos>0) mensagemNegativos="Sim";
    else mensagemNegativos="Não";
    if (nPrimos>0) mensagemPrimos="Sim";
    else mensagemPrimos="Não";

    cout << "Soma: " << soma << "\nMédia: " << media << "\nMaiores que a média: " << maiores << "\nNegativos? " << mensagemNegativos << ": " << nmensagemNegativos << "\nPrimos: " << mensagemPrimos << "\n";
    return 0;
}