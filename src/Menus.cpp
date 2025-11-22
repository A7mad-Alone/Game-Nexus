// By A7mad_Alone
// AKA Ahmad Adham
#include "Menus.h"
#include "Utilities.h"
#include "ScoreS.h"
#include "Users.h"
#include "Games.h" // This now includes all game headers
#include <bits/stdc++.h>
using namespace std;
using namespace Utilities;
//using namespace Score;
using namespace Users;
using namespace Games;
//V1.0
//==================================
//Menus.cpp Code Contents (Actual Functions Code).
//1.Main Menu Function.
//==================================
namespace Menu {
    void Menus::MainMenuWlc() {
        cout << "Hello and Welcome to the \"Game Nexus\"." <<endl;
    }
    void Menus::GameSelectionMenu() {
        clr();
        GameSelection = 0;
        Menus::GameSelectionMenuP1();
        clr();
        Menus::GameSelectionMenuP2();
    }
    void Menus::GameSelectionMenuP1() {
        do {
            cout << "Game Selection Menu"<< endl;
            sep(); 
            cout <<"Choose a Game: \n\n1: Coin Flip.\n2: Rock Paper Scissors.\n3: Guess The Number.\n4: Word Scramble.\n5: Number Memory Game.\n6: Worm Game.\n7: Random Game Selection.\n8: Main Menu." << endl;
            cin >> GameSelection;
            if (GameSelection > 8 || GameSelection < 1){
                WholeCheck();
                continue;
            }
            break;
        } while (true);
    }
    void Menus::GameSelectionMenuP2() {
        ScoreSystem G;
        switch (GameSelection){ 
            case 1: {
                G.coinFlipScoreS(); //TODO
                break;
            }
            case 2: {
                G.RPSScoreS(); //TODO
                break;
            }
            case 3: {
                G.GTNScoreS(); //TODO
                break;
            }
            case 4: {
                playWordScramble();
                paus();
                GameSelectionMenu();
                break;
            };
            case 5: {
                playNumberMemory();
                paus();
                GameSelectionMenu();
                break;
            };
            case 6: {
                playWormGame();
                paus();
                clr();
                GameSelectionMenu();
                break;
            };
            case 7: RandomGameSelection(); break;
            case 8: MainMenu(); break;
        }
    }
    void Menus::MainMenu() {
        clr();
        //TODO make an extra option for developer/admin to edit the user save files
        do {
            MainMenuWlc();
            sep();
            cout << "Choose an Option: \n1: Game Selection Menu.\n2: User Menu.\n3: Statistics.\n4: Credits.\n5: Exit." << endl;
            cin >> MainMenuSelection;
            if (MainMenuSelection > 5 || MainMenuSelection < 1){
                WholeCheck();
                continue;
            }
            break;
        } while (true);
        switch (MainMenuSelection){ 
            case 1: GameSelectionMenu(); break;
            //case 2: UserSelectionMenu(); break; //TODO
            case 2: {
                clr();
                cout << "Not Implemented Yet...\nCome Back Later when V2.0 Gets out." << endl;
                paus();
                MainMenu();
                break;
            }
            case 3: {
                clr();
                cout << "Not Implemented Yet...\nCome Back Later when V2.0 Gets out." << endl;
                paus();
                MainMenu();
                // Player P;
                // P.loadGameData();
                // paus();
                break;
            }
            case 4: CreditsMenu(); break;
            case 5: Ex(); break;
        }
    }
    void Menus::CreditsMenu() {
        clr();
        cout << "The \"Game Nexus\" Project is a C++ Course Project Made, Designed and Developed by Ahmad Adham, Eslam Mohammed, and Ali Abdel-Nasser.\nIt is a Nexus for the  Classic mini-games like Snake, Rock-Paper-Scissors, and memory challenges.\n";
        paus();
        MainMenu();
    }
    void Menus::RandomGameSelection() {
        GameSelection = (rand() %6)+1;
        GameSelectionMenuP2();
    }
}