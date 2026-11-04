#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
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
// 10 - ORDENAR POR ORDEM ALFABETICA

int main()
{
    // inicialização de variaveis
    int contRapazes=0, contMaximinos=0, menorAno=3000, menorIndex, auxAno;
    string auxNome, auxFreguesia, nome1, nome2;
    char auxSexo;

    // arrays com dados fornecidos pelo formador
    string nomes[20];
	nomes[0] = "Ana";
	nomes[1] = "Bela";
	nomes[2] = "Carlos";
	nomes[3] = "Carlito";
	nomes[4] = "Daniel";
	nomes[5] = "Diogo";
	nomes[6] = "Elvira";
	nomes[7] = "Fernanda";
	nomes[8] = "Fernando";
	nomes[9] = "Gilherme";
	nomes[10] = "Hilda";
	nomes[11] = "Joselfo";
	nomes[12] = "Josias";
	nomes[13] = "Maria";
	nomes[14] = "Anabela";
	nomes[15] = "Otaviano";
	nomes[16] = "Rui";
	nomes[17] = "Silvestre";
	nomes[18] = "Teodoro";
	nomes[19] = "Zacarias";

	string freguesias[20];
	freguesias[0] = "Maximinos";
	freguesias[1] = "Gualtar";
	freguesias[2] = "Lomar";
	freguesias[3] = "Lomar";
	freguesias[4] = "Silves";
	freguesias[5] = "Lameiro";
	freguesias[6] = "Maximinos";
	freguesias[7] = "Afife";
	freguesias[8] = "Maximinos";
	freguesias[9]  = "Silves";
	freguesias[10] = "Cabreira";
	freguesias[11] = "Silves";
	freguesias[12] = "Gualtar";
	freguesias[13] = "Silves";
	freguesias[14] = "Gualtar";
	freguesias[15] = "Maximinos";
	freguesias[16] = "Maximinos";
	freguesias[17] = "Maximinos";
	freguesias[18] = "Gualtar";
	freguesias[19] = "Lindoso";

	char sexos[20];
	sexos[0] = 'F';
	sexos[1] = 'F';
	sexos[2] = 'M';
	sexos[3] = 'M';
	sexos[4] = 'M';
	sexos[5] = 'M';
	sexos[6] = 'F';
	sexos[7] = 'F';
	sexos[8] = 'M';
	sexos[9]  = 'M';
	sexos[10] = 'F';
	sexos[11] = 'M';
	sexos[12] = 'M';
	sexos[13] = 'F';
	sexos[14] = 'F';
	sexos[15] = 'M';
	sexos[16] = 'M';
	sexos[17] = 'M';
	sexos[18] = 'M';
	sexos[19] = 'M';

	int anos[20];
	anos[0] = 1980;
	anos[1] = 2010;
	anos[2] = 1981;
	anos[3] = 1980;
	anos[4] = 1980;
	anos[5] = 1980;
	anos[6] = 2012;
	anos[7] = 1977;
	anos[8] = 1983;
	anos[9]  = 1989;
	anos[10] = 1980;
	anos[11] = 1981;
	anos[12] = 2009;
	anos[13] = 1975;
	anos[14] = 1980;
	anos[15] = 1988;
	anos[16] = 1987;
	anos[17] = 1980;
	anos[18] = 2015;
	anos[19] = 1986;

    // **********************************
    // 1 - LISTAR NOMES
    cout << "\n1 - LISTAR NOMES\n";
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << "\n";
    // **********************************


    // **********************************
    // 2 - LISTAR NOME, ANO, SEXO E FREGUESIA
    cout << "\n2 - LISTAR NOME, ANO, SEXO E FREGUESIA\n";
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << ", " << anos[i] << ", " << sexos[i] << ", " << freguesias[i] << "\n";
    // **********************************


    // **********************************
    // 3 - CONTAR RAPAZES
    cout << "\n3 - CONTAR RAPAZES\n";
    for (int i=0;i<20;i++) if (sexos[i]=='M') contRapazes++;
    cout << contRapazes << " rapazes.\n";
    // **********************************


    // **********************************
    // 4 - HÁ MAIS RAPAZES OU RAPARIGAS
    cout << "\n4 - HÁ MAIS RAPAZES OU RAPARIGAS\n";
    if (contRapazes>10) cout << "Há mais rapazes que raparigas.\n";
    else if (contRapazes<10) cout << "Há mais raparigas que rapazes.\n";
    else cout << "Há tantos rapazes como raparigas.\n";
    // **********************************


    // **********************************
    // 5 - QUANTOS MENINOS HÁ DE MAXIMINOS
    cout << "\n5 - QUANTOS MENINOS HÁ DE MAXIMINOS\n";
    for (int i=0;i<20;i++) if (sexos[i]=='M' && freguesias[i]=="Maximinos") contMaximinos++;
    cout << contMaximinos << " rapazes de Maximinos.\n";
    // **********************************


    // **********************************
    // 6 - QUEM É O MAIS VELHO
    cout << "\n6 - QUEM É O MAIS VELHO\n";
    for (int i=0;i<20;i++) {
        if (anos[i]<menorAno) {
            menorAno=anos[i];
            menorIndex=i;
        }
    }
    cout << "A pessoa mais velha é " << nomes[menorIndex] << ", do ano " << anos[menorIndex] << ".\n";
    // **********************************


    // **********************************
    // 7 - LER NOME; MUDAR ANO DE NASCIMENTO DESSA PESSOA
    cout << "\n7 - LER NOME; MUDAR ANO DE NASCIMENTO DESSA PESSOA\n";
    cout << "Insira um nome: ";
    cin >> nome1;

    for (int i=0;i<20;i++) {
        if (nome1==nomes[i]) {
            cout << "Insira uma nova data: " << "\n";
            cin >> anos[i];
        }
    }
    // **********************************


    // **********************************
    // 8 - LER DOIS NOMES; TROCAR AS FICHAS DE POSIÇÃO
    cout << "\n8 - LER DOIS NOMES; TROCAR AS FICHAS DE POSIÇÃO\n";

    cout << "Insira um nome: ";
    cin >> nome1;
    cout << "Insira outro nome: ";
    cin >> nome2;

    for (int i=0;i<20;i++) {
        for (int j=0;j<20;j++) {
            if (nome1==nomes[i] && nome2==nomes[j]) {
                // passar os i todos para variaveis auxiliares temporárias
                auxNome=nomes[i];
                auxAno=anos[i];
                auxFreguesia=freguesias[i];
                auxSexo=sexos[i];

                // passar todos os j para os i
                nomes[i]=nomes[j];
                anos[i]=anos[j];
                sexos[i]=sexos[j];
                freguesias[i]=freguesias[j];

                // passar das variaveis auxiliares para os j
                nomes[j]=auxNome;
                anos[j]=auxAno;
                freguesias[j]=auxFreguesia;
                sexos[j]=auxSexo;
            }
        }
    }

    // Mostrar a lista re-ordenada
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << ", " << anos[i] << ", " << sexos[i] << ", " << freguesias[i] << "\n";
    // **********************************


    // **********************************
    // 9 - QUAL A FREGUESIA MAIS REPRESENTADA
    cout << "\n9 - QUAL A FREGUESIA MAIS REPRESENTADA\n";
    //string auxFreguesias[20];
    //int contadorFreguesias[20];
    //bool guardada=false;
    //contains(freguesias, 'Maximinos');
    // **********************************


    // **********************************
    // 10 - ORDENAR POR ORDEM ALFABETICA
    cout << "\n10 - ORDENAR POR ORDEM ALFABETICA\n";
    for (int i=0;i<20;i++) {
        for (int j=0;j<20;j++) {
            if (nomes[i]<nomes[j]) {
                // passar os i todos para variaveis auxiliares temporárias
                auxNome=nomes[i];
                auxAno=anos[i];
                auxFreguesia=freguesias[i];
                auxSexo=sexos[i];

                // passar todos os j para os i
                nomes[i]=nomes[j];
                anos[i]=anos[j];
                sexos[i]=sexos[j];
                freguesias[i]=freguesias[j];

                // passar das variaveis auxiliares para os j
                nomes[j]=auxNome;
                anos[j]=auxAno;
                freguesias[j]=auxFreguesia;
                sexos[j]=auxSexo;
            }
        }
    }
    // Mostrar a lista re-ordenada    
    for (int i=0;i<20;i++) cout << i << ": " << nomes[i] << ", " << anos[i] << ", " << sexos[i] << ", " << freguesias[i] << "\n";
    // **********************************
    

    return 0;
}