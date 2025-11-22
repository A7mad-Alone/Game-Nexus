// By A7mad_Alone
// AKA Ahmad Adham
#include "GTN.h"
#include <bits/stdc++.h>
#include "Utilities.h"
using namespace std;
using namespace Utilities;
//V1.0
//==================================
//GTN.cpp Code Contents (Actual Functions Code).
//3.Guess The Number.
//==================================
namespace Games {
    void GTN::GTNGameRange() {
        do {
            cout << "Enter The Maximum Range Number :" <<endl;
            cin >> range;
            if (cin.fail()) {
                CheckCin();
                continue;
            }
            break;
        } while (true);
        randomNumber = rand() % range + 1;
    }
    void GTN::GTNPlay() {
        int guess;
        attempts = 0;
        clr();
        while (true) {
            do {
                cout << "The range is from 1 to " << range << ".\n";
                cout << "Enter your guess: ";
                cin >> guess;
                if (guess > range || guess < 1) {
                    WholeCheck(); //FIXME print the range again after clearing the screen
                    continue; 
                }
                break;
            } while (true);
            attempts++;
            clr();
            if (guess < randomNumber) {
                cout << "Too low!\n";
            } else if (guess > randomNumber) {
                cout << "Too high!\n";
            } else {
                cout << "Correct!\n";
                break;
            }
        }
        cout << "You guessed the number in " << attempts << " attempts.\n";
    }
    void GTN::GTNStart() {
        GTNGameRange();
        GTNPlay();
    }
}