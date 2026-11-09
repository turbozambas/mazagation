#include <string>
#include <iostream>
using namespace std;

char board[3][8];
int paths[2][16][2]={
    {{2,4},{2,3},{2,2},{2,1},{2,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,7},{2,6},{2,5}},
    {{0,4},{0,3},{0,2},{0,1},{0,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{0,7},{0,6},{0,5}}
};
int rosettes[5][2]={{0,0},{2,0},{1,3},{0,6},{2,6}};
int rosettesPosition[3]={4,8,14};
int startPosition=0,endPosition=15;

int main() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<8;j++) {
            for (int k=0;k<5;k++) {
                for (int l=0;l<2;l++) {
                    if (i+j==rosettes[k][l]) board[i][j]='*';
                    else board[i][j]='$';
                    
                }
            }
            cout << board[i][j];
            if (j==7) cout << "\n";
        }
    }
}