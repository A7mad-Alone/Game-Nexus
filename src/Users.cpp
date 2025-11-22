// By A7mad_Alone
// AKA Ahmad Adham
#include "Users.h"
#include "Utilities.h"
#include <bits/stdc++.h>
#include <json.hpp>
using namespace std;
using namespace Utilities;
using json = nlohmann::json;

//V1.0
//==================================
//Menus.cpp Code Contents (Actual Functions Code).
//1.Main Menu Function.
//==================================
namespace Users {
    void Player::saveGame(const string& filePath = "game_data.json") {
        json saveData;
        saveData["username"] = username;
        saveData["rank"] = rank;
        saveData["game_code"] = gameCode;
        saveData["game_name"] = gameName;
        saveData["highscore"] = highScore;
        saveData["score_history"] = scoreHistory;
        ofstream file(filePath);
        file << saveData.dump(4);
        file.close();
        cout << "Game data saved to " << filePath << endl;
    }
    void Player::loadGame(const string& filePath = "game_data.json") {
        ifstream file(filePath);
        if (file) {
            json saveData;
            file >> saveData;
            cout << "Loaded User: " << saveData["username"] << endl;
            cout << "Rank: " << saveData["rank"] << endl;
            cout << "High Score: " << saveData["high_score"] << endl;
            cout << "Score History: " << saveData["score_history"] << endl;
            cout << "Game Name & Code: " << saveData["game_name"] << " " << saveData["game_code"] << endl;
        } else {
            cout << "Failed to load game data from " << filePath << endl;
        }
    }
    void Player::saveGameData() {
        void saveGame(const string& filePath);
    }
    void Player::loadGameData() {
        void loadGame(const string& filePath);
    }
}