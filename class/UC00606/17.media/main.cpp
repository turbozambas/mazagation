#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m17. Média de classificações\033[0m\n\n";
	// Leia sucessivamente classificações de 0 de 20. A introdução termina com -1.
	// Apresente a média das classificações válidas e a quantidade de classificações iguais ou superiores a 10.
	// Trate a situação em que não é introduzida nenhuma classificação válida--

	int n, total=0, positivas=0, contador=0;
	double media;

	do {
		cout << "Insira uma classificação: ";
		cin >> n;

		if (n>=0 && n<=20) {
			if (n>=10) { positivas++; }
			total=total+n;
			contador++;
		} else if (n==-1) {
			cout << "\n";
		} else {
			cout << "Número inválido.\n";
		}
	} while (n!=-1);

	media = total/contador;
	cout << "Média: " << media << "\n";
	cout << "Positivas: " << positivas << "\n";
}