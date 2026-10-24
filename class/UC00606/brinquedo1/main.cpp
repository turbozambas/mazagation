#include <iostream>
#include <string>
using namespace std;

void cardinal(int n) {
	if (n%3==0) cout << "# ";
	else cout << "#";
}

int main() {
	cout << "\033[1mBrinquedo - Representação gráfica da temperatura\033[0m\n\n";

	int temp;
	cout << "Insira uma temperatura em ºC: ";
	cin >> temp;

	if (temp%2==0) {
		for (int i=1;i<=temp/2;i++) {
			cardinal(i);
		}
	} else {
		for (int i=1;i<=(temp-1)/2;i++) {
			cardinal(i);
		}
		cout << "+";
	}
	cout << "\n";
}