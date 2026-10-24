#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "\033[1m13. Classificação de uma temperatura\033[0m\n\n";
	// Leia uma temperatura em graus Celsius e apresente: Frio (inferior a 10 ºC); Agradável (de 10 ºC a menos de 25 ºC); Quente (igual ou superior a 25 ºC)--

	double temp;
	cout << "Registe a temperatura: ";
	cin >> temp;

	if (temp < 10) cout << "Está frio!\n";
	else if (temp >= 25) cout << "Está calor!\n";
	else cout << "Morninho!\n";
}