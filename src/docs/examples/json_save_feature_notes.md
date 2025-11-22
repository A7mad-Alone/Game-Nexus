# Design Notes: Implementing a JSON-Based Save System

This document outlines a plan for implementing a save/load system for the Game Nexus project using the `nlohmann/json` library.

## 1. Why Use JSON?

JSON (JavaScript Object Notation) is a human-readable and lightweight format for structuring data. It's perfect for a save system because it can easily represent complex data like user profiles, settings, and score histories in a simple text file.

## 2. Proposed JSON Structure

A single JSON file (e.g., `gamenexus_data.json`) could store all data, organized by user.

```json
{
  "users": [
    {
      "username": "Ahmad",
      "highscore": 9500,
      "game_scores": {
        "WormGame": 8000,
        "WordScramble": 1200,
        "NumberMemory": 300
      },
      "settings": {
        "sound": true,
        "default_difficulty": "Normal"
      }
    },
    {
      "username": "Player2",
      "highscore": 500,
      "game_scores": {
        "CoinFlip": 10,
        "RPS": 40
      },
      "settings": {
        "sound": false,
        "default_difficulty": "Easy"
      }
    }
  ]
}
```

## 3. C++ Code Examples

Here are some example functions demonstrating how to read from and write to this JSON structure. These could be integrated into the `Users.cpp` and `ScoreS.cpp` files.

### A. Saving Game Data

This function takes the current state of a player and saves it to the JSON file. It would need to find the correct user in the JSON and update their data, or add a new user if they don't exist.

```cpp
#include <fstream>
#include "json.hpp" // Assumes nlohmann/json is available

using json = nlohmann::json;

// Example function to save a user's data
void saveUserData(const std::string& username, int new_score) {
    json gameData;
    const std::string saveFile = "gamenexus_data.json";

    // 1. Read existing data from the file
    std::ifstream inFile(saveFile);
    if (inFile) {
        gameData = json::parse(inFile);
    } else {
        // If the file doesn't exist, create a default structure
        gameData["users"] = json::array();
    }
    inFile.close();

    // 2. Find the user and update their data
    bool userFound = false;
    for (auto& user : gameData["users"]) {
        if (user["username"] == username) {
            user["highscore"] = std::max((int)user["highscore"], new_score);
            // ... update other scores and settings ...
            userFound = true;
            break;
        }
    }

    // 3. If the user is new, add them
    if (!userFound) {
        gameData["users"].push_back({
            {"username", username},
            {"highscore", new_score},
            {"game_scores", {}},
            {"settings", {{"sound", true}, {"default_difficulty", "Normal"}}}
        });
    }

    // 4. Write the updated data back to the file
    std::ofstream outFile(saveFile);
    outFile << gameData.dump(4); // .dump(4) formats the JSON with an indent of 4 spaces
    outFile.close();

    std::cout << "User data for " << username << " saved." << std::endl;
}
```

### B. Loading Game Data

This function would load a specific user's data from the JSON file into the application's state.

```cpp
// Example function to load a user's data
void loadUserData(const std::string& username) {
    json gameData;
    const std::string saveFile = "gamenexus_data.json";

    std::ifstream inFile(saveFile);
    if (!inFile) {
        std::cout << "Save file not found." << std::endl;
        return;
    }
    gameData = json::parse(inFile);

    for (const auto& user : gameData["users"]) {
        if (user["username"] == username) {
            int highscore = user["highscore"];
            std::cout << "Loaded user: " << user["username"] << ", Highscore: " << highscore << std::endl;
            // ... load other scores and settings into the game ...
            return;
        }
    }

    std::cout << "User '" << username << "' not found." << std::endl;
}
```

## 4. Integration Plan

1.  **User Management:** Modify `Menus.cpp` and `Users.cpp` to create a simple "Login" or "Select User" screen at the start of the application.
2.  **Load Data:** After a user is selected, call a `loadUserData` function.
3.  **Save Data:** After a game is completed, call a `saveUserData` function to update their scores.
4.  **Score System:** The `ScoreS` class can be refactored to work with the loaded user data.

These notes provide a clear path for implementing the planned save/load functionality.
