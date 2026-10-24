#include <iostream>
#include <string>
using namespace std;

void linha() {
	for (int i=1;i<=20;i++) {
		cout << "=";
		if (i==20) {
			cout << "\n";
		}
	}
}

int main() {
	cout << "\033[1m22. Mostrar uma linha\033[0m\n\n";
	// Crie uma função void linha() que apresente 20 sinais de igual (=). No main(), chame a função antes e depois de apresentar o título O meu programa--
	
	linha();
	cout << "O meu programa\n";
	linha();
}