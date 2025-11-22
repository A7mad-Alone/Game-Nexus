// By A7mad_Alone
// AKA Ahmad Adham
#ifndef Menus_H
#define Menus_H
#include <bits/stdc++.h>
#include "ScoreS.h"
//using namespace Score;
//V1.0
//==================================
//Menus.h Library Contents (Declaration).
//1.Main Menu Function.
//==================================
namespace Menu {
    class Menus {
        protected:
            int GameSelection, MainMenuSelection;
            void MainMenuWlc();
            void CreditsMenu();
            void RandomGameSelection();
            void GameSelectionMenuP1();
            void GameSelectionMenuP2();
        public:
            void GameSelectionMenu();
            void MainMenu();
    };
}
#endif 