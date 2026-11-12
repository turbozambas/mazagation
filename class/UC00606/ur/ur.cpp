#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include <string>
using namespace std;

// core game mechanics declarations
int turn=0, rng; // turn and turn's roll
bool win=false, tryAgain=false; 
string reset="\033[0m", bold="\033[1m";
string landing, beadsList;

// player related declarations
struct Player {
    string tag, color;
    int beads[7], p, paths[16][2];
};
Player players[2];
bool player,opponent;

// board related declarations
string board[3][8];
int paths[2][16][2]={
    {{2,4},{2,3},{2,2},{2,1},{2,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,7},{2,6},{2,5}},
    {{0,4},{0,3},{0,2},{0,1},{0,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{0,7},{0,6},{0,5}}
};
int rosettes[5][2]={{0,0},{2,0},{1,3},{0,6},{2,6}};
int rolls[5], sumR;

// RNG (cppreference.com/cpp/numeric/random/uniform_int_distribution)
int randomNumber(int x, int y) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(x, y);
    return dist(gen);
}

void init() {
    cout << "\n\n\t  ##############################" << endl; // hello!
    cout << "\t  ### " << bold << "** ROYAL GAME OF UR **" << reset << " ###" << endl; // hello!
    cout << "\t  ##############################"<< endl; // hello!
    // player related initialization
    players[0].tag='Y';
    players[1].tag='B';
    players[0].color="\033[38;2;217;164;65m";
    players[1].color="\033[38;2;75;165;225m";
    for (int i=0;i<2;i++) for (int j=0;j<7;j++) players[0].beads[j]=0;
    for (int i=0;i<5;i++) rolls[i]=0;
    for (int i=0;i<16;i++) {
        for (int j=0;j<2;j++) {
            players[0].paths[i][j]=paths[0][i][j];
            players[1].paths[i][j]=paths[1][i][j];
        }
    }
    players[0].p=1;
    players[1].p=2;
}

int checkBeads(int p, int pos) {
    int c=0, s=0;
    beadsList="";
    for (int i=0;i<7;i++) {
        if (players[p].beads[i]==15) {
            beadsList+=" "+players[p].tag+to_string(i);
            s++;
        }
        if (players[p].beads[i]==pos) c++;
    }
    return c;
}

void printBoard() {
    cout << endl;
    cout << players[player].color << bold << "\tPlayer " << players[player].p << " rolls " << rng << reset;
    cout << endl;
    for (int i=0;i<3;i++) for (int j=0;j<8;j++) board[i][j]="  ";
    for (int i=0;i<5;i++) board[rosettes[i][0]][rosettes[i][1]]="**";
    for (int i=0;i<2;i++) for (int j=0;j<7;j++) board[paths[i][players[i].beads[j]][0]][paths[i][players[i].beads[j]][1]]=bold+players[i].color+players[i].tag+to_string(j)+reset;
    cout << endl;
    // prep info
    string info[7]={"\t\tRoyal Game of Ur","\t\tRoll:","","","","\t\tP1:","\t\tP2:"};
    info[1]="\t\tRoll: "+to_string(rng);
    info[5]="\t\t"+players[0].color+"P1["+to_string(checkBeads(0,0))+"]["+to_string(checkBeads(0,15))+"]"+beadsList; // set P1 home and score
    info[6]="\t\t"+players[1].color+"P2["+to_string(checkBeads(1,0))+"]["+to_string(checkBeads(1,15))+"]"+beadsList; // set P2 home and score
    // map board
    string canvas[7][17] = {
        {"\t##","##","##","##","##","##","##","##","##",board[0][4],"  ",board[0][5],"##","##","##","##","##"+bold+info[0]+reset},
        {"\t##",board[0][0],"##",board[0][1],"##",board[0][2],"##",board[0][3],"##","  ","  ","  ","##",board[0][6],"##",board[0][7],"##"+bold+info[1]+reset},
        {"\t##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##"+bold+info[2]+reset},
        {"\t##",board[1][0],"##",board[1][1],"##",board[1][2],"##",board[1][3],"##",board[1][4],"##",board[1][5],"##",board[1][6],"##",board[1][7],"##"+bold+info[3]+reset},
        {"\t##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##"+bold+info[4]+reset},
        {"\t##",board[2][0],"##",board[2][1],"##",board[2][2],"##",board[2][3],"##","  ","  ","  ","##",board[2][6],"##",board[2][7],"##"+bold+info[5]+reset},
        {"\t##","##","##","##","##","##","##","##","##",board[2][4],"  ",board[2][5],"##","##","##","##","##"+bold+info[6]+reset}
    };
    // print board
    for (int i=0;i<7;i++) {
        for (int j=0;j<17;j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

void errorMsg() {
    cout << bold << "\n\tThese aren't the droids you're looking for. Move along!\n" << reset;
}

void setPlayer() { // turn decides who plays next
    if (turn%2==0) {
        player=0;
        opponent=1;
    }
    else {
        player=1;
        opponent=0;
    }
}

bool checkCellIsFree(int pos) {
    for (int i=0;i<7;i++) if ((players[player].beads[i]==pos && pos!=15) || (players[opponent].beads[i]==pos && pos==8)) return false;
    return true;
}

void resetOpponentsBead(int pos) {
    for (int i=0;i<7;i++) if (players[opponent].beads[i]==pos && pos>=5 && pos<=12 && pos!=8) players[opponent].beads[i]=0;
}

int move(int o, int pos) {
    board[players[player].paths[o][0]][players[player].paths[o][1]]="  "; // clears previous position
    players[player].beads[o]+=rng; // move bead to new position
    landing="  ";
    for (int i=0;i<5;i++) { // records landing position
        if (players[player].paths[pos][0]==rosettes[i][0] && players[player].paths[pos][1]==rosettes[i][1]) {
            landing="**";
            break;
        }
    }
    board[players[player].paths[o][0]][players[player].paths[o][1]]=players[player].tag;
    tryAgain=false;
    resetOpponentsBead(pos);
    if (landing=="**") return 0;
    else turn++;
    return 0;
}

void askPlayerMove() {
    char opt;
    cout << "\n\t" << bold << players[player].color << "Player " << players[player].p << reset << players[player].color << " move a bead (0-6) by " << bold << rng << reset << players[player].color << " spaces or pass (P)... " << reset;
    cin >> opt;
    if (opt=='P' || opt=='p') {
        turn++;
        tryAgain=false;
    }
    else if (opt-'0'>=0 && opt-'0'<7 && players[player].beads[opt-'0']+rng<16 && checkCellIsFree(players[player].beads[opt-'0']+rng)) move(opt-'0', players[player].beads[opt-'0']+rng);
    else {
        errorMsg();
        tryAgain=true;
    }
}

void rollDice() {
    rng=0; // reset dices
    for (int i=0;i<4;i++) rng+=randomNumber(0,1); // run rng 4 times for propper roll chances
    rolls[rng]++; // update roll counts
    printBoard();
    if (rng>0) askPlayerMove();
    if (rng==0) turn++; // automatically pass when roll is 0
}

void checkWinConditions() {
    for (int i=0;i<2;i++) {
        int c=0; // elderlywomanbehindacounterinasmalltown
        for (int j=0;j<7;j++) if (players[i].beads[j]==15) c++;
        if (c==7) win=true;
    }
}

void printRolls() { // print rolls counts when game is over
    cout << bold << "\n\tRolls:";
    for (int i=0;i<5;i++) {
        cout << bold << "\n\t" << i << reset << "[" << rolls[i] << "]";
        sumR+=rolls[i];
        for (int j=0;j<rolls[i];j++) cout << "#";
    }
    cout << bold << "\n\tT" << reset << "[" << sumR << "]";
}

int main() {
    init();
    do {
        setPlayer();
        if (tryAgain) askPlayerMove();
        else rollDice();
        checkWinConditions();
    } while (!win);
    printBoard();
    printRolls();
    cout << bold << "\n\n\tGAME OVER\n" << endl;
    return 0;
}