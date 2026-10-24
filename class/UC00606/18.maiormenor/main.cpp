#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m18. Maior e menor número\033[0m\n\n";
	// Peça a quantidade de números inteiros que o utilizador pretende introduzir.
	// Leia esse números e apresente o maior e o menor.
	// Garanta que a quantidade indicada é superior a zero--

	int quantidade, n, maior, menor;

	cout << "Quantos números pretende introduzir? ";
	cin >> quantidade;

	if (quantidade>0) {
		for (int i=1;i<=quantidade;i++) {
			cout << "Insira um número: ";
			cin >> n;

			if (i==1) {
				maior=n;
				menor=n;
			} else {
				if (n>maior) { maior=n; }
				if (n<menor) { menor=n; }
			}
		}
	}

	cout << "Maior: " << maior << "\n";
	cout << "Menor: " << menor << "\n";
}