#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m14. Desconto numa compra\033[0m\n\n";
	// Leia o nome de um cliente e o valor de uma compra. Aplique 10% de desconto se o valor for igual ou superior a 100€;
	// caso contrário, não aplique desconto. Apresente o nome, o desconto e o valor final--

	double total = 0, desconto = 0;
	string cliente;

	cout << "Insira o nome do cliente: ";
	cin >> cliente;
	cout << "Insira o valor total da compra: ";
	cin >> total;

	if (total >= 100) {
		desconto = total * 0.1;
		total = total * 0.9;
	}

	cout << "\nCliente: " << cliente << "\nDesconto: " << desconto << "€\nPreço Final: " << total << "€\n";
}