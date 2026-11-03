#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

int main() {
	srand(time(NULL)); // Random Number Generator

	// Declaração de variaveis locais
	int tabuleiro[5], r=rand() % 5, contTentativas=1, tentativa;
	bool win=false;

	// Esconder o tesouro...
	for (int i=0;i<5;i++) {
		if (i==r) { tabuleiro[i]=7; } // ...algures onde o i coincidir com o número anteriormente gerado
		else { tabuleiro[i]=0; }
	}

	do { // Ciclo que termina após vitória ou 3 tentativas erradas
		cout << "Encontre o tesouro (0-4): ";
		cin >> tentativa;
		if (tentativa>=0 && tentativa<=4) { // Caso seja jogada válida...
			if (contTentativas==3 && tentativa!=r) { // ...caso seja a última tentativa errada
				cout << "YOU LOSE.\n";
				break;
			}
			if (tentativa==r) { // ...caso seja tentativa certa
				cout << "YOU WIN!\n";
				win=true;
				break;
			} else cout << "TRY AGAIN...\n";
			contTentativas++;
		} else cout << "INVALID MOVE!\n"; // jogadas inválidas não contam como tentativas
	} while (contTentativas<=3 || tentativa!=r || win==false);

	// Mostra a solução no fim de cada jogo
	cout << "SOLUTION: | ";
	for (int i=0;i<5;i++) cout << tabuleiro[i] << " | ";
	cout << "\nGAME OVER, BYE BYE NOW!\n";

	return 0;
}