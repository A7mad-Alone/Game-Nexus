// By A7mad_Alone
// AKA Ahmad Adham
#include "RPS.h"
#include <bits/stdc++.h>
#include "Utilities.h"
using namespace Utilities;
using namespace std;
//V1.0
//==================================
//RPS.cpp Code Contents (Actual Functions Code).
//2.Rock Paper Scissors.
//==================================
namespace Games {
    void RPS::RPSComputerChoice() {
        randomChoice = rand() % 3; 
        if (randomChoice == 0) {
            computerChoice = "Rock";
        } else if (randomChoice == 1) {
            computerChoice = "Paper";
        } else {
            computerChoice = "Scissors";
        }
        cout << "Computer chose: " << computerChoice << endl;
        cout << "You chose: " << playerChoice << endl;
    }
    void RPS::RPSPlayerChoice() {
        do {
            cout << "Enter your choice :\n1: Rock.\n2: Paper.\n3: Scissors." <<endl;
            cin >> playerInput;
            if (playerInput > 3 || playerInput < 1) {
                WholeCheck();
                continue;
            }
            break;
        } while (true);
        if (playerInput == 1) {
            playerChoice = "Rock";
        } else if (randomChoice == 2) {
            playerChoice = "Paper";
        } else {
            playerChoice = "Scissors";
        }
    }
    void RPS::RPSWinner() {
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == "Rock" && computerChoice == "Scissors") ||
                (playerChoice == "Scissors" && computerChoice == "Paper") ||
                (playerChoice == "Paper" && computerChoice == "Rock")) {
            cout << "You won!" << endl;
        } else {
            cout << "You lost!" << endl;
        }
    }
    void RPS::RPSStart() {
        RPSPlayerChoice();
        clr();
        RPSComputerChoice();
        sep();
        RPSWinner();
    }
}