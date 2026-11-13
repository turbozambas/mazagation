#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include <string>
#include <cstdlib>
using namespace std;

// core game mechanics declarations
int turn=0, rng; // turn and turn's roll
bool win=false, tryAgain=false; 
string white="\033[38;2;232;225;211m", gray="\033[38;2;166;162;154m", reset="\033[0m", bold="\033[1m";
string landing, beadsList;

// player related declarations
struct Player {
    string tag, color, selector;
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

// last N dice rolls structure and declarations
struct rollRecord {
    int roll;      // dice roll (0-4)
    int player;     // P1 or P2
};
const int HISTORY_SIZE=7; // sets history size
rollRecord lastRolls[HISTORY_SIZE];
int historyCount=0, historyHead=0; // counters
string showLastRolls;

// Clear Screen (https://www.cppbetterexplained.com/posts/cpp-clear-console-screen/)
void clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux/macOS
#endif
}

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

void pushRoll(int r, int p) {
    lastRolls[historyHead].roll=r;
    lastRolls[historyHead].player=p;
    historyHead=(historyHead+1) % HISTORY_SIZE;
    if (historyCount<HISTORY_SIZE) historyCount++;
}

void calcLastRolls() {
    showLastRolls="";
    int idx = (historyHead-historyCount+HISTORY_SIZE) % HISTORY_SIZE; // start from the oldest entry
    for (int i=0;i<historyCount;++i) {
        int p=lastRolls[idx].player;
        showLastRolls+=players[p].color+"["+to_string(lastRolls[idx].roll)+"]";
        idx=(idx+1) % HISTORY_SIZE;
    }
    cout << "\n";
}

void printBoard() {
    clearScreen();
    cout << endl;
    if (win) cout << players[player].color << bold << "\tPlayer " << players[player].p << " WINS!" << reset;
    else cout << players[player].color << bold << "\tPlayer " << players[player].p << " rolls " << rng << reset;
    cout << endl;
    for (int i=0;i<3;i++) for (int j=0;j<8;j++) board[i][j]="  "; // reset board
    for (int i=0;i<5;i++) board[rosettes[i][0]][rosettes[i][1]]="**"; // print rosettes
    for (int i=0;i<2;i++) {
        for (int j=0;j<7;j++) { // print beads
            board[paths[i][players[i].beads[j]][0]][paths[i][players[i].beads[j]][1]]=bold+players[i].color+players[i].tag+to_string(j)+reset;
        }
    }
    cout << endl;

    // prep info
    string info[7];
    info[0]=white+"\t\t The Royal Game of Ur";
    info[2]=white+"\t\t Roll: "+to_string(rng);
    info[3]=white+"\t\t Last "+to_string(HISTORY_SIZE)+": "+showLastRolls;
    info[5]=white+"\t\t"+players[0].selector+players[0].color+"P1["+to_string(checkBeads(0,0))+"]["+to_string(checkBeads(0,15))+"]"+beadsList; // set P1 home and score
    info[6]=white+"\t\t"+players[1].selector+players[1].color+"P2["+to_string(checkBeads(1,0))+"]["+to_string(checkBeads(1,15))+"]"+beadsList; // set P2 home and score
    
    // map board
    string canvas[7][17] = {
        {gray+"\t\t##","##","##","##","##","##","##","##","##",board[0][4],"  ",board[0][5],gray+"##","##","##","##","##"+bold+info[0]+reset},
        {gray+"\t\t##",board[0][0],gray+"##",board[0][1],gray+"##",board[0][2],gray+"##",board[0][3],gray+"##","  ","  ","  ","##",board[0][6],gray+"##",board[0][7],gray+"##"+bold+info[1]+reset},
        {gray+"\t\t##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##"+bold+info[2]+reset},
        {gray+"\t\t##",board[1][0],gray+"##",board[1][1],gray+"##",board[1][2],gray+"##",board[1][3],gray+"##",board[1][4],gray+"##",board[1][5],gray+"##",board[1][6],gray+"##",board[1][7],gray+"##"+bold+info[3]+reset},
        {gray+"\t\t##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##","##"+bold+info[4]+reset},
        {gray+"\t\t##",board[2][0],gray+"##",board[2][1],gray+"##",board[2][2],gray+"##",board[2][3],gray+"##","  ","  ","  ","##",board[2][6],gray+"##",board[2][7],gray+"##"+bold+info[5]+reset},
        {gray+"\t\t##","##","##","##","##","##","##","##","##",board[2][4],"  ",board[2][5],gray+"##","##","##","##","##"+bold+info[6]+reset}
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
    cout << bold << white << "\n\tThese aren't the droids you're looking for. Move along!\n" << reset;
}

void setPlayer() { // turn decides who plays next
    if (turn%2==0) {
        player=0;
        opponent=1;
        players[0].selector='>';
        players[1].selector=' ';
    }
    else {
        player=1;
        opponent=0;
        players[0].selector=' ';
        players[1].selector='>';
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
    tryAgain=false; // reset flag
    resetOpponentsBead(pos);
    if (landing=="**") return 0; // roll again
    else turn++;
    return 0;
}

void askPlayerMove() {
    char opt;
    cout << "\n\t" << bold << players[player].color << "Player " << players[player].p << reset << players[player].color << " move a bead (0-6) by " << bold << rng << reset << players[player].color << " spaces or pass (P)... " << reset;
    cin >> opt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears remaining numbers on current input
    if (opt=='P' || opt=='p') {
        turn++;
        tryAgain=false;
    }
    else if (opt-'0'>=0 && opt-'0'<7 && players[player].beads[opt-'0']+rng<16 && checkCellIsFree(players[player].beads[opt-'0']+rng)) move(opt-'0', players[player].beads[opt-'0']+rng);
    else {
        errorMsg();
        tryAgain=true;  // ask again
    }
}

void rollDice() {
    rng=0; // reset dices
    for (int i=0;i<4;i++) rng+=randomNumber(0,1); // run rng 4 times for propper roll chances
    rolls[rng]++; // update roll counters
    pushRoll(rng, player);
    calcLastRolls();
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

void printRolls() { // print roll counters when game is over
    cout << bold << "\n\n\tDice Rolls:";
    for (int i=0;i<5;i++) {
        cout << bold << white << "\n\t" << i << reset << ": [" << rolls[i] << "]\t";
        sumR+=rolls[i];
        for (int j=0;j<rolls[i];j++) cout << "#";
    }
    cout << bold << white << "\n\tT" << reset << ": [" << sumR << "]";
}

int main() {
    init(); // initialization
    do { // main game cycle
        setPlayer(); // sets both player's flags
        if (tryAgain) askPlayerMove(); // bypasses dice rolls if needed
        else rollDice(); // rolls 4 binary dices
        checkWinConditions(); // counts each player's beads
    } while (!win);
    printBoard(); // prints the board
    printRolls(); // prints roll statistics
    cout << bold << "\n\n\tGAME OVER\n" << endl;
    return 0;
}