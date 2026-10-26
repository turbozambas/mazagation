#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

int main() {
	srand(time(NULL));
	int tabuleiro[5], r=rand() % 5, tentativas=1, tentativa;
	bool win=false;

	for (int i=0;i<5;i++) {
		if (i==r) { tabuleiro[i]=7; }
		else { tabuleiro[i]=0; }
	}

	do {
		cout << "Adivinha a posição da bomba: ";
		cin >> tentativa;
		if (tentativa>=0 && tentativa<=4) {
			if (tentativas==3 && tentativa!=r) {
				cout << "YOU LOSE. GAME OVER!\n";
				break;
			}
			if (tentativa==r) {
				cout << "YOU WIN. GAME OVER!\n";
				win=true;
				break;
			} else {
				cout << "TRY AGAIN...\n";
			}
			tentativas++;
		} else { cout << "INVALID MOVE!\n"; }
	} while (tentativas<=3 || tentativa!=r);

	if (win==false) {
		cout << "SOLUTION: | ";
		for (int i=0;i<5;i++) {
			cout << tabuleiro[i] << " | ";
		}
		cout << "\n";
	}

	return 0;
}