#include <iostream>
using namespace std;

// Declare uma struct Produto com nome e preço. Crie um produto e apresente os seus dados
struct Produto {
    string nome;    
    double preco;
};

int main()
{
    Produto produtos[2];
    produtos[0].nome = "Arroz";
    produtos[1].nome = "Banana";
    produtos[0].preco = 1.19;
    produtos[1].preco = 3.69;
    for (int i = 0;i < 2;i++) cout << produtos[i].nome << " " << produtos[i].preco << endl;
}