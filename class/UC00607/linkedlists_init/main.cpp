#include <iostream>
using namespace std;

struct No { int valor; string nome; No* seguinte; };
int main()
{
	
	No* primeiro = new No{ 10, "Ana", nullptr };
	No* segundo = new No{ 20, "Bruno", nullptr };
	No* terceiro = new No{ 30, "Carla", nullptr };

	(*primeiro).seguinte = segundo;
	(*segundo).seguinte = terceiro;

	No* atual = primeiro;
	while (atual != nullptr) {
		cout << (*atual).valor << " - " << (*atual).nome << endl;
		atual = (*atual).seguinte;
	}

	atual = primeiro;
	while (atual != nullptr) {
		No* proximo = (*atual).seguinte;
		atual = proximo;
	}
	primeiro = nullptr;
}