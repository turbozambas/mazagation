#include <string>
#include <iostream>
using namespace std;

// 1 - LISTAR NOMES
// 2 - LISTAR NOME, ANO, SEXO E FREGUESIA
// 3 - CONTAR RAPAZES
// 4 - HÁ MAIS RAPAZES OU RAPARIGAS
// 5 - QUANTOS MENINOS HÁ DE MAXIMINOS
// 6 - QUEM É O MAIS VELHO
// 7 - LER NOME; MUDAR ANO DE NASCIMENTO DESSA PESSOA
// 8 - LER DOIS NOMES; TROCAR AS FICHAS DE POSIÇÃO
// 9 - QUAL A FREGUESIA MAIS REPRESENTADA
// 10 - ORDEM ALFABETICA

// arrays com dados fornecidos pelo formador
string nomes[20]={"Ana","Bela","Carlos","Carlito","Daniel","Diogo","Elvira","Fernanda","Fernando","Gilherme","Hilda","Joselfo","Josias","Maria","Anabela","Otaviano","Rui","Silvestre","Teodoro","Zacarias"};
string freguesias[20]={"Maximinos","Gualtar","Lomar","Lomar","Silves","Lameiro","Maximinos","Afife","Maximinos","Silves","Cabreira","Silves","Gualtar","Silves","Gualtar","Maximinos","Maximinos","Maximinos","Gualtar","Lindoso"};
char sexos[20]={'F','F','M','M','M','M','F','F','M','M','F','M','M','F','F','M','M','M','M','M'};
int anos[20]={1980,2010,1981,1980,1980,1980,2012,1977,1983,1989,1980,1981,2009,1975,1980,1988,1987,1980,2015,1986};

void bubblesort(int i, int j) {
    // *** BUBBLESORT ***

    // passar os i todos para arrays auxiliares
    string auxNome=nomes[i], auxFreguesia=freguesias[i];
    int auxAno=anos[i];
    char auxSexo=sexos[i];

    // passar todos os j para os i
    nomes[i]=nomes[j];
    anos[i]=anos[j];
    sexos[i]=sexos[j];
    freguesias[i]=freguesias[j];

    // passar dos arrays auxiliares para os j
    nomes[j]=auxNome;
    anos[j]=auxAno;
    freguesias[j]=auxFreguesia;
    sexos[j]=auxSexo;
}

int main() {
    // **********************************
    cout << "1 - LISTAR NOMES\n";
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << "\n";
    // **********************************


    // **********************************
    cout << "\n2 - LISTAR NOME, ANO, SEXO E FREGUESIA\n";
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << ", " << anos[i] << ", " << sexos[i] << ", " << freguesias[i] << "\n";
    // **********************************


    // **********************************
    cout << "\n3 - CONTAR RAPAZES\n";
    int contRapazes=0;
    for (int i=0;i<20;i++) if (sexos[i]=='M') contRapazes++;
    cout << contRapazes << " rapazes.\n";
    // **********************************


    // **********************************
    cout << "\n4 - HÁ MAIS RAPAZES OU RAPARIGAS\n";
    if (contRapazes>10) cout << "Há mais rapazes que raparigas.\n";
    else if (contRapazes<10) cout << "Há mais raparigas que rapazes.\n";
    else cout << "Há tantos rapazes como raparigas.\n";
    // **********************************


    // **********************************
    cout << "\n5 - QUANTOS MENINOS HÁ DE MAXIMINOS\n";
    int contMaximinos=0;
    for (int i=0;i<20;i++) if (sexos[i]=='M' && freguesias[i]=="Maximinos") contMaximinos++;
    cout << contMaximinos << " rapazes de Maximinos.\n";
    // **********************************


    // **********************************
    cout << "\n6 - QUEM É O MAIS VELHO\n";
    int menorAno=3000, menorIndex;
    for (int i=0;i<20;i++) {
        if (anos[i]<menorAno) {
            menorAno=anos[i];
            menorIndex=i;
        }
    }
    cout << "A pessoa mais velha é " << nomes[menorIndex] << ", nasceu em " << anos[menorIndex] << ".\n";
    // **********************************


    // **********************************
    cout << "\n7 - LER NOME; MUDAR ANO DE NASCIMENTO DESSA PESSOA\n";
    string nome1, nome2;
    cout << "Insira um nome: ";
    cin >> nome1;

    for (int i=0;i<20;i++) {
        if (nome1==nomes[i]) {
            cout << "Insira uma nova data: ";
            cin >> anos[i];
        }
    }
    // **********************************


    // **********************************
    cout << "\n8 - LER DOIS NOMES; TROCAR AS FICHAS DE POSIÇÃO\n";
    cout << "Insira um nome: ";
    cin >> nome1;
    cout << "Insira outro nome: ";
    cin >> nome2;

    for (int i=0;i<20;i++) for (int j=0;j<20;j++) if (nome1==nomes[i] && nome2==nomes[j]) bubblesort(i,j);
    // Mostrar a lista re-ordenada
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << ", " << anos[i] << ", " << sexos[i] << ", " << freguesias[i] << "\n";
    // **********************************


    // **********************************
    cout << "\n9 - QUAL A FREGUESIA MAIS REPRESENTADA\n";
    int contFreguesias=0, maxFreguesia=0;
    string maxFreguesiaNome;

    for (int i=0;i<20;i++) {
        contFreguesias=0;
        for (int j=0;j<20;j++) if (freguesias[i]==freguesias[j]) contFreguesias++;
        if (contFreguesias>maxFreguesia) {
            maxFreguesia=contFreguesias;
            maxFreguesiaNome=freguesias[i];
        }
        cout << freguesias[i] << " " << contFreguesias << "\n";
    }
    cout << "Maior freguesia: " << maxFreguesiaNome << " " << maxFreguesia << "\n";
    // **********************************


    // **********************************
    cout << "\n10 - ORDEM ALFABETICA\n";
    for (int i=0;i<20;i++) for (int j=0;j<20;j++) if (nomes[i]<nomes[j]) bubblesort(i,j);
    // Mostrar a lista re-ordenada    
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << ", " << anos[i] << ", " << sexos[i] << ", " << freguesias[i] << "\n";
    // **********************************
    

    return 0;
}