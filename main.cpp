#include <windows.h>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Virtual Machine Global Variables
int pc=0;
int operand;
int acc;
int opcode;
int Memory_data_register = 0;
int command;
int Programcounter=0;
//Virtual Machine Functions
int menu();
void VMstart(int);
void about();
void load();
void display();
void documentation();
void execute(int);
void run();
//Virtual Machine Constants; Instruction set
const int CLR  = 0;   // acc = 0
const int LOAD = 1;   // not implemented
const int ADD = 2;   // acc = acc + operand
const int SUB = 3;   // acc = acc - operand
const int DIV = 4;
const int MUL = 5;
const int OUTPUT = 6;
const int HALT = 0xFF;  // HEX opcode to hlt cpu 244
const int JMP = 7;      // pc = jmp's operand
const int BNZ = 8;      // Branch Not Zero  operand . if (acc != 0) pc = operand
const int STORES = 9;
const int RUN = 10;
const int QUIT = 11;
//Our Ram with certain amounts of data;
int RAM[10000];
string RAMdisplay[10000];

int main()
{
    while(true)
    {
        command = menu();
        if (command == 6){cout << "We are exiting virutal machine..."; return 0;} //Digit 6 represents quit.
        VMstart(command);
    }
    return 0;
}

void VMstart(int command){
    switch(command)
        {
            case 1: //About
                about();
                break;

            case 2: //Load data from text file
                load();
                break;

            case 3: //Display data in our RAM
                display();
                break;

            case 4: //Run
                run(); // Run will lead to execution of our opcode
                break;
            case 5:
                documentation();
                break;
            default:
                cout << "Virtual Machine Exiting, Fatal error" << endl;
                exit(EXIT_FAILURE);
                system("pause");
                break;
        }
}

void run () {
    if(Programcounter == 0){cout << "Error Cannot Run without loading data first\n"; system("pause"); return;}
        while(true)
        {
            opcode = RAM[pc]; //Grab the current opcode, starting from the beginning of our RAM.
            execute(opcode);
            if (opcode==HALT || opcode==QUIT)
            {
                cout << "Value of Accumulator is: " << acc << endl;
                if (Memory_data_register != 0){cout << "Value of memory is: " << Memory_data_register << endl;}
                cout << "We are halting or quitting the virtual machine....." << endl;
                system("pause");
                return;
            }
        }
}
//Fetch Execute Cycle ALU
void execute(int opcode)
{
    switch (opcode) //Our opcode to determine what to do with each command inside of our RAM
    {
        case ADD:
                operand = RAM[++pc];
                acc += operand;
                pc++;
                break;
        case SUB:
                operand = RAM[++pc];
                acc -= operand;
                pc++;
                break;
        case MUL:
                operand = RAM[++pc];
                acc *= operand;
                pc++;
                break;
        case BNZ:
                operand = RAM[++pc];
                if ( acc != 0 ) pc = operand;
                else pc++;
                break;
        case CLR:
                acc = 0;
                pc++;
                break;
        case DIV:
                operand = RAM[++pc];
                if (operand != 0) { acc /= operand; }else{ acc = 0; }
                pc++;
                break;
        case JMP:
                operand = RAM[++pc];
                pc = operand;
                break;
        case OUTPUT:
                cout << "The content of the accumulator is: " << acc << endl;
                pc++;
                break;
        case STORES:
                Memory_data_register = acc; //
                pc++;
                break;
        case HALT:
                break;
        default:
            cout << "Unidentified word " << opcode << endl;
    }
}
//Open file and fetch each word seperated by a space and store it into our ram
void load()
{
    string filename,word;
    int i = 0;

    cout << "Enter file name in current directory: ";
    cin >> filename;
    ifstream input(filename.c_str());

    if(!input.is_open())
    {
        cout << "Your file was not found: " << endl;
        system("pause");
        return;
    }
    cout << "File found:" << endl;
    system("pause");
    //As long as we don't reach the end of the file continue to load data into our RAM
    while(!input.eof())
    {
        input >> word;
        RAMdisplay[i]=word;
        if(word=="CLR")             //Virtual machine commands that are allowed in your text file
        {
            RAM[i]=CLR;
        }
        else if(word=="ADD")
        {
            RAM[i]=ADD;
        }
        else if(word=="SUB")
        {
            RAM[i]=SUB;
        }
        else if(word=="DIV")
        {
            RAM[i]=DIV;
        }
        else if(word=="MUL")
        {
            RAM[i]=MUL;
        }
        else if(word=="OUT")
        {
            RAM[i]=OUTPUT;
        }
        else if(word=="HALT")
        {
            RAM[i]=HALT;
        }
        else if(word=="JMP")
        {
            RAM[i]=JMP;
        }
        else if(word=="BNZ")
        {
            RAM[i]=BNZ;
        }
        else if(word=="STORE")
        {
            RAM[i]=STORES;
        }
        else if(word=="RUN")
        {
            RAM[i]=RUN;
        }
        else if(word=="QUIT")
        {
            RAM[i]=QUIT;
        }
        else
        {
            stringstream number(word);
            number >> RAM[i];
            if (word!="QUIT" && word!="RUN" && word!="BNZ" && word!="JMP" && word!="HALT" && word!="OUT" && word!="MUL" && word!="DIV" && word!="SUB" && word!="ADD" && word!="CLR"){
                //A check in order to see if our virtual machine instructions are loadable.
                if(!number >> RAM[i]){
                    cout << "Error Loading data unidentified: " << word << endl;
                    system("pause");
                    return;
                }
            }
        }
        i++;
    }
    Programcounter = i;
    cout << "Data Processed"<< endl;
    input.close();
    system("pause");
}

void display()
{
    cout << "Displaying Data" << endl;
    if(Programcounter != 0){
        for(int i=0; i<Programcounter; i++)
        {
            cout << RAMdisplay[i] << endl;
        }
        system("pause");
    }else{cout << "Error cannot display data there is no data in our RAM" << endl; system("pause"); return;}
}

int menu()
{
    int choice;
    system("CLS");

    cout << "Simple CPU" << endl;
    cout << "1....About" << endl;
    cout << "2...Load Program" << endl;
    cout << "3...Display Program" << endl;
    cout << "4...Run Program" << endl;
    cout << "5...Documentation" << endl;
    cout << "6...QUIT" << endl;
    cout << "Choice:";

    cin >> choice;
    cout << endl;
    return choice;
}

void about()
{
    cout <<"Menu driven Calculator + Virtual Machine Version 1.0\n";
    cout <<"(c) copyright 2015 Araf Shihab. All rights reserved.\n" << endl;
    system("pause");
}


void documentation()
{
    cout << "HELP" << endl << endl;
    cout << "1) IF The result of the vm is different from the result I did manually." << endl;
    cout << "   --------" << "Make sure the commands that you type in your text file are proper commands" << endl << endl;
    cout << "Commands Available: CLR QUIT RUN BNZ JMP HALT OUT MUL DIV SUB ADD STORE" << endl;
    system("pause");
}
