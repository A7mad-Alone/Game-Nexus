// By A7mad_Alone
// AKA Ahmad Adham
#include "CoinFlip.h"
#include <bits/stdc++.h>
#include "Utilities.h"
using namespace std;
using namespace Utilities;
//V1.0
//==================================
//CoinFlip.cpp Code Contents (Actual Functions Code).
//1.Coin Flip.
//==================================
namespace Games {
    void CoinFlip::CoinComputerChoice() {
        randomChoice = rand() % 2 +1;
    }
    void CoinFlip::CoinPlayerChoice() {
        do {
            cout << "Select Heads or Tails:\n1: Heads.\n2: Tails. " <<endl;
            cin >> playerInput;
            if (playerInput != 1 && playerInput != 2) {
                WholeCheck();
                continue;
            }
            break;
        } while (true);

    }
    void CoinFlip::CoinWinner() {
        cout << ((playerInput == randomChoice) ? "You lost!" : "You won!") << " The result was " << (randomChoice == 2 ? "Heads." : "Tails.") << endl;
    }
    void CoinFlip::CoinStart() {
        CoinComputerChoice();
        CoinPlayerChoice();
        clr();
        CoinWinner();
    }
}