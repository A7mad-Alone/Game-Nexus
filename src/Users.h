// By A7mad_Alone
// AKA Ahmad Adham
#ifndef Users_H
#define Users_H
#include <bits/stdc++.h>
#include "ScoreS.h"
//V1.0
//==================================
//Menus.h Library Contents (Declaration).
//1.Main Menu Function.
//==================================
namespace Users {
    class gamesData : public ScoreSystem {
        public:
            string gameName, rank;
            int gameCode, highScore;
            list <int> scoreHistory;
    };
    class Player : public gamesData {
        private:
            static constexpr const char* defaultFilePath = "game_data.json"; 
            string saveFilePath;
            void saveGame(const string& filePath);
            void loadGame(const string& filePath);
        public:
            string username;
            Player() : username("guest_user") {
                rank = "Not Implemented Yet";
                gameCode = 0;
                gameName = "Unknown";
                highScore = 0;
                scoreHistory = {};
                saveFilePath = defaultFilePath;
            }
            Player(string un, string r, int gc, string gn, int hs, list<int> sh) : username(un) {
                rank = r;
                gameCode = gc;
                gameName = gn;
                highScore = hs;
                scoreHistory = sh;
                saveFilePath = defaultFilePath;
            }
            void saveGameData();
            void loadGameData();
    };
}
#endif 