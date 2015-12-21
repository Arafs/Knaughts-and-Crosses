//Arafullah Shihab
//Knaughts and Crosses Lab.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

string table[9] = {"1","2","3","4","5","6","7","8","9"};
string player = "X"; //First Player
int fullTable = 0;
int playagainStateMachine = 0;


void showBoard();
void playerInput();
string checkWinner();
string tableNotFull();
void changePlayer();
void checkState();
void clearTable();

int main(){
    showBoard();
    while (1)
    {
        fullTable++;
        playerInput();
        showBoard();
        if (checkWinner() == "X")
        {
            cout << "\nPlayer 1: X wins!" << endl;
            playagainStateMachine = 1;
            checkState();
        }
        else if (checkWinner() == "O")
        {
            cout << "\nPlayer 2: O wins!" << endl;
            playagainStateMachine = 1;
            checkState();
        }
        else if (checkWinner() == "DRAW" && fullTable == 9)
        {
            cout << "\nIt's a draw! No winner!" << endl;
            playagainStateMachine = 1;
            checkState();
        }
        changePlayer();
    }
    system("pause");
    return 0;
}


void checkState(){
    char a;
    if (playagainStateMachine != 0) {
            cout << "\nWould you like to play again 'Y' for yes 'N' for no" << endl;
            cin >> a;
            a = toupper(a);
            if (a == 'N'){
                cout << "\nExiting tic tac toe" << endl;
                exit(EXIT_FAILURE);
            }else if(a == 'Y'){
                clearTable();
                showBoard();
            }else{
                cout << "\nEntered incorrect data, game exiting" << endl; exit(EXIT_FAILURE);
            }
        }
    if (playagainStateMachine == 1){
        cout << "\nWho will go first 'X' or 'O'?: " << endl;
        cin >> a;
        a = toupper(a);
        if (a == 'X'){ player = "X"; }
        if (a == 'Y') { player = "O"; }
    }
}

void clearTable(){
    for(int i = 0; i < 9; i++){
        if(i == 8){table[i] = "9";}
        if(i == 7){table[i] = "8";}
        if(i == 6){table[i] = "7";}
        if(i == 5){table[i] = "6";}
        if(i == 4){table[i] = "5";}
        if(i == 3){table[i] = "4";}
        if(i == 2){table[i] = "3";}
        if(i == 1){table[i] = "2";}
        if(i == 0){table[i] = "1";}
    }
}

void showBoard(){
    system("cls");
    cout << "Tic Tac Toe Board" << endl;
    for(int i = 0; i < 9; i++){
        if(i == 3 || i == 6){
            cout << endl;
        }
        cout << " " << table[i] << " ";
       }
}

void playerInput(){
    int a;
    cout << endl << "It's " << player << " turn. " <<"Press the number of the field: " << endl;
    cin >> a;

    switch(a){
        case 1:
            if (table[0] == "1"){
                table[0] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 2:
            if (table[1] == "2"){
                table[1] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 3:
            if (table[2] == "3"){
                table[2] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 4:
            if (table[3] == "4"){
                table[3] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 5:
            if (table[4] == "5"){
                table[4] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 6:
            if (table[5] == "6"){
                table[5] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 7:
            if (table[6] == "7"){
                table[6] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 8:
            if (table[7] == "8"){
                table[7] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
        case 9:
            if (table[8] == "9"){
                table[8] = player;
            }
            else
            {
                cout << "I'm sorry field is in use please try another position" << endl;
                playerInput();
            }
            break;
    }
}
void changePlayer()
{
    if (player == "X")
        player = "O";
    else
        player = "X";
}
string checkWinner()
{
    //first player
    if (table[0] == "X" && table[1] == "X" && table[2] == "X")
        return "X";
    if (table[0] == "X" && table[3] == "X" && table[6] == "X")
        return "X";
    if (table[1] == "X" && table[4] == "X" && table[7] == "X")
        return "X";

    if (table[3] == "X" && table[6] == "X" && table[9] == "X")
        return "X";
    if (table[4] == "X" && table[5] == "X" && table[6] == "X")
        return "X";
    if (table[6] == "X" && table[7] == "X" && table[8] == "X")
        return "X";

    if (table[3] == "X" && table[5] == "X" && table[7] == "X")
        return "X";
    if (table[0] == "X" && table[4] == "X" && table[8] == "X")
        return "X";

    //second player
    if (table[0] == "O" && table[1] == "O" && table[2] == "O")
        return "O";
    if (table[0] == "O" && table[3] == "O" && table[6] == "O")
        return "O";
    if (table[1] == "O" && table[4] == "O" && table[7] == "O")
        return "O";

    if (table[2] == "O" && table[5] == "O" && table[8] == "O")
        return "O";
    if (table[4] == "O" && table[5] == "O" && table[6] == "O")
        return "O";
    if (table[7] == "O" && table[8] == "O" && table[9] == "O")
        return "O";

    if (table[3] == "O" && table[5] == "O" && table[7] == "O")
        return "O";
    if (table[0] == "O" && table[4] == "O" && table[8] == "O")
        return "O";

    return "DRAW";
}

