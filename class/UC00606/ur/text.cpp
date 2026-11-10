#include <iostream>
#include <string>
using namespace std;

struct Player {
        char tag;
        string color;
        int beads[7];
        bool p;
        int paths[16][2];
    };

int paths[2][16][2]={
    {{2,4},{2,3},{2,2},{2,1},{2,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,7},{2,6},{2,5}},  // player1
    {{0,4},{0,3},{0,2},{0,1},{0,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{0,7},{0,6},{0,5}}   // player2
};

int main() {
    
    
    Player players[2];
    players[0].tag='B';
    players[1].tag='Y';
    players[0].color='\033[38;2;217;164;65m';
    players[1].color='\033[38;2;75;165;225m';
    for (int i=0;i<7;i++) {
        players[0].beads[i]=0;
        players[1].beads[i]=0;
    } 
    for (int i=0;i<16;i++) {
        for (int j=0;j<2;j++) {
            players[0].paths[i][j]=paths[0][i][j];
            players[1].paths[i][j]=paths[1][i][j];
        }
    }   
    players[0].p=2;
    players[1].p=1;
    cout << players[0].paths[10][10];
    return 0;
}