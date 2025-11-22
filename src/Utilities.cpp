// By A7mad_Alone
// AKA Ahmad Adham
#include "Utilities.h"
#include "Menus.h"
#include "Users.h"
#include <bits/stdc++.h>
#include <json.hpp>
#include <thread> // Required for std::this_thread::sleep_for
#include <chrono> // Required for std::chrono::seconds
using json = nlohmann::json;
using namespace std;
using namespace Menu;
using namespace Users;
//V1.0
//==================================
//Utilities.cpp Code Contents (Actual Functions Code).
//
//1.Welcome Function.
//2.Clearing Cin Function.
//3.Checking Cin Function.
//4.Exit Function.
//5.Seperation Function.
//==================================
namespace Utilities {
    void GameWlc(string Game) {
        cout << "Hello and Welcome to the " << Game << "." <<endl;
    }
    void ClearCin() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    void CheckCin() {
        if (cin.fail()){
            clr();  
            cout << "Invalid Input! Try again using a Number!" << endl;
            sep();
            cin.clear();
            ClearCin();  
        }
    }
    void WholeCheck() {
        clr();
        cout << "Invalid Option! Try again!"<<endl;
        sep();
        CheckCin();
    }
    void Ex() {
        system("cls");
        cout << "Thank U for using Game Nexus, Have a good day!" <<endl;
        system("pause");
        exit(0);
    }
    void sep() {
        cout << "====================" << endl;
    }
    void clr() {
        system("cls");
    }
    void paus() {
        system("pause");
    }
    // Function to create a delay for a given number of seconds
    void waitForSeconds(int seconds) {
        cout << "Waiting for " << seconds << " seconds...\n";
        this_thread::sleep_for(chrono::seconds(seconds));
        cout << "\nTime's up!\n";
    }
    void conti() {
        int ContSelection = 0;
        do {
            sep();
            cout << "Continue Playing?\n1: Continue Playing.\n2: Back To Game Selection Menu.\n3: Back To Main Menu." << endl;
            cin >> ContSelection;
            if (ContSelection > 3 || ContSelection < 1){
                WholeCheck();
                continue;
            }
            break;
        } while (true);
        Menus M;
        //Player P;
        switch (ContSelection){
            case 1: {
                //P.saveGameData();
                clr(); 
                return;
            }
            case 2: M.GameSelectionMenu(); break;
            case 3: M.MainMenu(); break;
        }
    }

    int getValidatedNumericInput() {
        int value;
        while (true) {
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number: ";
            } else {
                return value;
            }
        }
    }
}