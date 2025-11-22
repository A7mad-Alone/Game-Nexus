// By A7mad_Alone
// AKA Ahmad Adham
#include <bits/stdc++.h>
// #include <windows.h>
// #include <json.hpp>
#include "Games.h"
#include "Menus.h"
#include "Utilities.h"
// #include "Users.h"
#include "ScoreS.h"
//#include "termcolor.hpp"
//#include <raylib.h>
//#include <raymath.h>
using namespace std;
using namespace Games;
using namespace Menu;
using namespace Utilities;
// using namespace Users;
//using namespace Score;
// using json = nlohmann::json;

//V1.0
//==================================
//Game Nexus
//1.Coin Flip. (No Difficulity, Low Points, Score history is like Win(ملك), Lose(كتابة), High score based on win streak)
//2.Rock Paper Scissors. (No Difficulity, Low Points, Score history is like Win(ملك), Lose(كتابة), High score based on win streak)
//3.Guess The Number. (User Select Max number (can be randomised), Mid Points, Number of Attempts, High score based on the lowest number of attempts)
//4.Word Scramble. (Requieres a database of many words distrubed across the difficulties) (Easy-Normal-Hard-Extreme-Insane, Mid Points, Word-Time Taken, High score based on time taken- Difficulity, The higher the difficulity the more score)
//5.Number Memory Game. (Easy-Normal-Hard-Extreme-Insane (Difficulity changes 1.Time for each number shown. 2.How many numbers shown on the screen. 3.Time left for trial. 4.Time for showing the numbers.), Mid Points, Number-Time Taken, High score based on time taken- Difficulity, The higher the difficulity the more score)
//6.Worm Game (Main GAME). (Difficulity System: Easy, Normal, Hard, Extreme, Insane, Custom)
//7.Random mode, whether it was a random game or it was a random user input/difficulity for specific games)
//...Math Quiz. (CANCELED)
//...Simple Quiz Game. (CANCELED) (Requieres a database of many words distrubed across the difficulties) (Easy-Normal-Hard-Extreme-Insane, High Points, Score History: Qs-Answers-Win or Lose, High score based on time taken- Difficulity, The higher the difficulity the more score)
//Add A score system, users, high score for each user and across all users, score history, a difficulty system for specific games and points system.
//All of that should be saved in an external file
//==================================    
int main() {
    srand(time(0));
    // ScoreSystem G1;
    // G1.coinFlipScoreS();
    // RPS G2;
    // G2.RPSStart();
    // GTN G3;
    // G3.GTNStart();
    // Player P;
    // P.saveGameData();
    Menus M1;
    M1.MainMenu();
    system("pause");
}


// Yes, the **virtual function** mechanism, combined with polymorphism, can achieve what you described. You can use a base class to define a common interface (e.g., for handling `gameCode` and `gameName`), and each derived class can have its own specific `gameCode` and `gameName`. This design enables a system (like your `ScoreSystem`) to call the appropriate behavior based on the derived class at runtime.

// Here’s how you can implement this:

// ### Step-by-Step:

// #### 1. Define the **Base Class**:
// The base class will have a pure virtual function (or virtual function if default behavior is needed) for operations like setting `gameCode` and `gameName`.

// ```cpp
// class Game {
// protected:
//     int gameCode;
//     std::string gameName;

// public:
//     // Pure virtual function to initialize gameCode and gameName
//     virtual void setGameDetails() = 0;

//     // Getter methods for gameCode and gameName
//     int getGameCode() const { return gameCode; }
//     std::string getGameName() const { return gameName; }

//     virtual ~Game() {} // Virtual destructor for proper cleanup
// };
// ```

// #### 2. Create **Derived Classes** for Each Game:
// Each derived class implements the `setGameDetails()` method to assign its specific `gameCode` and `gameName`.

// ```cpp
// class Game1 : public Game {
// public:
//     void setGameDetails() override {
//         gameCode = 101;
//         gameName = "Rock Paper Scissors";
//     }
// };

// class Game2 : public Game {
// public:
//     void setGameDetails() override {
//         gameCode = 102;
//         gameName = "Guess the Number";
//     }
// };

// class Game3 : public Game {
// public:
//     void setGameDetails() override {
//         gameCode = 103;
//         gameName = "Word Scramble";
//     }
// };
// ```

// #### 3. Extend the `ScoreSystem` Class:
// This class can manage games and decide behavior based on `gameCode` at runtime using polymorphism.

// ```cpp
// class ScoreSystem {
// private:
//     Game* currentGame; // Pointer to the current game (polymorphic usage)

// public:
//     void setGame(Game* game) {
//         currentGame = game;
//         currentGame->setGameDetails();
//     }

//     void runGame() {
//         std::cout << "Running Game: " << currentGame->getGameName() << "\n";
//         std::cout << "Game Code: " << currentGame->getGameCode() << "\n";

//         // Call specific functions based on the gameCode
//         switch (currentGame->getGameCode()) {
//             case 101:
//                 std::cout << "Launching Rock Paper Scissors...\n";
//                 break;
//             case 102:
//                 std::cout << "Launching Guess the Number...\n";
//                 break;
//             case 103:
//                 std::cout << "Launching Word Scramble...\n";
//                 break;
//             default:
//                 std::cout << "Unknown game.\n";
//         }
//     }
// };
// ```

// #### 4. Main Function Example:
// You can instantiate each game and pass it to the `ScoreSystem`.

// ```cpp
// int main() {
//     ScoreSystem scoreSystem;

//     Game1 game1;
//     Game2 game2;
//     Game3 game3;

//     scoreSystem.setGame(&game1);
//     scoreSystem.runGame();

//     scoreSystem.setGame(&game2);
//     scoreSystem.runGame();

//     scoreSystem.setGame(&game3);
//     scoreSystem.runGame();

//     return 0;
// }
// ```

// ### Output:
// ```
// Running Game: Rock Paper Scissors
// Game Code: 101
// Launching Rock Paper Scissors...

// Running Game: Guess the Number
// Game Code: 102
// Launching Guess the Number...

// Running Game: Word Scramble
// Game Code: 103
// Launching Word Scramble...
// ```

// ### How It Works:
// 1. **Polymorphism**:
//    - The `ScoreSystem` class uses a pointer to the `Game` base class to interact with derived classes.
//    - The appropriate `setGameDetails()` function is called based on the actual derived class passed.

// 2. **Encapsulation of Behavior**:
//    - Each derived class encapsulates its own `gameCode` and `gameName`.

// 3. **Scalability**:
//    - Adding new games only requires creating new derived classes with specific implementations of `setGameDetails()`.

// This design is robust and leverages object-oriented principles, ensuring clean and manageable code as the system grows.