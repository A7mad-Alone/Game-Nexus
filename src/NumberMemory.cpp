#include "NumberMemory.h"
#include "Utilities.h" // Assuming Utilities has getValidatedNumericInput or similar if needed

using namespace std;
using namespace Utilities; // Assuming Utility namespace

void clearScreen() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear");  // For Unix/Linux/Mac
#endif
}

MemoryGame::MemoryGame() : level(1), attempts(0) {}

void MemoryGame::generateNumbers() {
    numbers.clear();
    for (int i = 0; i < 3 + (level - 1); ++i) {
        int num = rand() % 10;
        numbers.push_back(num);
    }
}

void MemoryGame::showNumbers() {
    cout << "Memorize these numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Wait for 3 seconds
    this_thread::sleep_for(chrono::seconds(3));

    // Clear the console screen to make numbers disappear
    clearScreen();

    cout << "Now, the numbers disappear!\n";
}

bool MemoryGame::getUserInput() {
    vector<int> userNumbers(numbers.size());
    cout << "Enter the numbers you saw: ";

    for (int i = 0; i < numbers.size(); ++i) {
        while (!(cin >> userNumbers[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
    }

    // Compare user input with generated numbers
    for (int i = 0; i < numbers.size(); ++i) {
        if (userNumbers[i] != numbers[i]) {
            return false;
        }
    }

    return true;
}

void MemoryGame::play() {
    while (true) {
        generateNumbers();
        showNumbers();

        if (getUserInput()) {
            cout << "Correct! Moving to Level " << level + 1 << endl;
            level++;
            attempts++;
        } else {
            cout << "Wrong! Game Over at Level " << level << endl;
            cout << "Total Attempts: " << attempts << endl;

            int choice;
            cout << "\nDo you want to play again?\n";
            cout << "Press 1 to play again, 0 to exit: ";
            while (!(cin >> choice) || (choice != 0 && choice != 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Press 1 to play again, 0 to exit: ";
            }

            if (choice == 0) {
                cout << "Exiting the game. Thank you for playing!\n";
                break;
            } else {
                cout << "\nRestarting the game...\n";
                level = 1;
                attempts = 0;
                break;
            }
        }
    }
}

void playNumberMemory() {
    srand(time(0));  // Seed the random number generator for this game

    MemoryGame game;

    int choice;
    cout << "Welcome to the Memory Challenge Game!\n";
    cout << "Press 1 to start the game: ";

    while (!(cin >> choice) || choice != 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please press 1 to start: ";
    }

    game.play();
}