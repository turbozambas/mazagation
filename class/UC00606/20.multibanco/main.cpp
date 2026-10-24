#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m20. Simulação de uma caixa multibanco\033[0m\n\n";
	// Crie um programa com saldo inicial de 500€. Apresente erpetidamente um menu com as opções:
	// 1 - Consultar saldo;
	// 2 - Depositar dinheiro;
	// 3 - Levantar dinheiro;
	// 4 - Sair.
	// Rejeite valores não positivos e levantamentos superiores ao saldo.
	// Repita o menu até ser escolhida a opção 4--

	int op, saldo = 500, deposito, levantamento;

	do {
		cout << "\n1 - Consultar saldo\n";
		cout << "2 - Depositar dinheiro\n";
		cout << "3 - Levantar dinheiro\n";
		cout << "4 - Sair\n";
		cin >> op;
		if (op==1) {
			cout << "Saldo: " << saldo << "€\n";
		} if (op==2) {
			cout << "Quantia a depositar: ";
			cin >> deposito;
			if (deposito > 0) {
				saldo=saldo+deposito;
			}
		} if (op==3) {
			cout << "Quantia a levantar: ";
			cin >> levantamento;
			if (levantamento>0 && levantamento<=saldo) {
				saldo=saldo-levantamento;
				cout << "RETIRE O SEU DINHEIRO!\n";
				cout << "Saldo: " << saldo << "€\n";
			}
		} if (op==4) {
			break;
		}
	} while (op!=4);
}