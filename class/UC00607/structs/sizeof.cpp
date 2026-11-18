#include <iostream>
using namespace std;

struct Tipo {
	int n1;
	double n2;
};

int main() {
	Tipo coiso;
	coiso.n1 = 10;
	coiso.n2 = 20;
	cout << sizeof(coiso);
}