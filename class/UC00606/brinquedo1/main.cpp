#include <iostream>
#include <string>
using namespace std;

// REPRESENTAÇÃO GRÁFICA DA TEMPERATURA

// Esta função agrupa os cardinais em grupos de 3; Cada grupo representa 6ºC
void cardinal(int n) {
	if (n%3==0) cout << "\033[1m#\033[0m ";
	else cout << "\033[1m#\033[0m";
}

int main() {
	cout << "\033[1mBrinquedo 1 - Representação gráfica da temperatura\033[0m\n\n";

	// Leitura da temperatura
	int temp;
	cout << "Insira uma temperatura em ºC: ";
	cin >> temp;

	if (temp%2==0) for (int i=1;i<=temp/2;i++) cardinal(i); // Caso seja par divide a temperatura por 2 e pinta tudo com '#'
 	else { // Caso seja impar, retira um valor antes de dividir por 2...
		for (int i=1;i<=(temp-1)/2;i++) cardinal(i);
		cout << "\033[1m+\033[0m"; // ...por fim coloca o valor '+' subtraído no ciclo
	}
	cout << "\n";
	return 0;
}