#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m17. Média de classificações\033[0m\n\n";

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