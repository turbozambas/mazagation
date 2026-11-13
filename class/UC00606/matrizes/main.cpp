#include <iostream>
#include <stdio.h>
using namespace std;

// listar
// contar positivos
// utilizador escolhe 2 posições; tocar valores
// listar

// matriz
int M[3][3]={77,12,14,7,0,-1,101,99,1003};

void listar() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void contarPositivos() {
    int contador=0;
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (M[i][j]>0) contador++;
    cout << "Positivos: " << contador << endl;
}

void trocar() {
    int o, opt[2][2], aux;
    for (int i=0;i<2;i++) {
        if (i==0) cout << "Insira as posições do primeiro valor" << endl;
        else cout << "Insira as posições do segundo valor" << endl;
        for (int j=0;j<2;j++) {
            if (i==0) cout << "Linha: ";
            else cout << "Coluna: ";
            cin >> o;
            if (o>0 && o<4) opt[i][j]=o-1;
        }
    }
    aux=M[opt[0][0]][opt[0][1]];
    M[opt[0][0]][opt[0][1]]=M[opt[1][0]][opt[1][1]];
    M[opt[1][0]][opt[1][1]]=aux;
}

void transpor() {
    int aux[2][2];
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) aux[i][j]=M[i][j];
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) M[j][i]=aux[i][j];
}

int main() {
    system("cls");
    listar();
    //contarPositivos();
    //trocar();
    //listar();
    transpor();
    listar();
    return 0;
}