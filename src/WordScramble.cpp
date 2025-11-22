#include "WordScramble.h"
#include "Utilities.h"
#include <bits/stdc++.h>
#include <random> // For std::shuffle
#include <chrono>  // For std::chrono::system_clock
using namespace Utilities;

string scrambleWord(const string& word) {
    string scrambled = word;
    do {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(scrambled.begin(), scrambled.end(), g);
    } while (scrambled == word);
    return scrambled;
}
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}
void WordScrambleGame::playGame() {
    if (words.empty()) {
        cout << "No words available for this difficulty. Exiting game.\n";
        return;
    }
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(words.begin(), words.end(), std::default_random_engine(seed));

    score = 0;
    attempts = 0;
    positivePoints = 0;
    minusPoints = 0;
    for (int i = 0; i < min(10, (int)words.size()); i++) {
        string word = words[i];
        string scrambledWord = scrambleWord(word);
        cout << "Scrambled word: " << scrambledWord << endl;
        cout << "Your guess: ";
        string userGuess;
        cin >> userGuess;
        attempts++;
        if (toLowerCase(userGuess) == toLowerCase(word)) {
            cout << "Correct! You earn points.\n";
            int points = getPointsForCorrectAnswer();
            positivePoints += points;
            score += points;
        } else {
            cout << "Wrong! The correct word was: " << word << ".\n";
            int penalty = getPointsForWrongAnswer();
            minusPoints += penalty;
            score -= penalty;
            if (score < 0) score = 0;
        }
        cout << "Your current score: " << score << endl;
    }
}
int WordScrambleGame::getAttempts() const { return attempts; }
int WordScrambleGame::getPositivePoints() const { return positivePoints; }
int WordScrambleGame::getMinusPoints() const { return minusPoints; }
int WordScrambleGame::getScore() const { return score; }

void EasyMode::setWords() {
    words = {"apple", "book", "car", "time", "tree", "light", "house", "cat", "dog", "key"};
}
int EasyMode::getPointsForCorrectAnswer() { return 2; }
int EasyMode::getPointsForWrongAnswer() { return 1; }
void MediumMode::setWords() {
    words = {"challenge", "teacher", "student", "database", "project", "strategy", "library", "network"};
}
int MediumMode::getPointsForCorrectAnswer() { return 4; }
int MediumMode::getPointsForWrongAnswer() { return 2; }
void HardMode::setWords() {
    words = {"component", "algorithm", "database", "refactor", "compiler", "execution", "gateway", "service"};
}
int HardMode::getPointsForCorrectAnswer() { return 6; }
int HardMode::getPointsForWrongAnswer() { return 3; }
void ExtremeMode::setWords() {
    words = {"platform", "developer", "gateway", "database", "adapter", "optimization", "code", "service"};
}
int ExtremeMode::getPointsForCorrectAnswer() { return 8; }
int ExtremeMode::getPointsForWrongAnswer() { return 4; }
void InsaneMode::setWords() {
    words = {"compiler", "integration", "automation", "repository", "parameter", "format", "branch", "server"};
}
int InsaneMode::getPointsForCorrectAnswer() { return 10; }
int InsaneMode::getPointsForWrongAnswer() { return 5; }
int getDifficulty() {
    int diff;
    cout << "Choose Difficulty (1 - Easy, 2 - Medium, 3 - Hard, 4 - Extreme, 5 - Insane, 0 - Exit): ";
    diff = getValidatedNumericInput();

    while (diff < 0 || diff > 5) {
        cout << "Invalid choice. Please select a number between 0 and 5: ";
        diff = getValidatedNumericInput();
    }
    return diff;
}

void playWordScramble() {
    int diff = getDifficulty();
    WordScrambleGame* game = nullptr;

    switch (diff) {
        case 1:
            game = new EasyMode();
            break;
        case 2:
            game = new MediumMode();
            break;
        case 3:
            game = new HardMode();
            break;
        case 4:
            game = new ExtremeMode();
            break;
        case 5:
            game = new InsaneMode();
            break;
        default:
            cout << "Exiting Word Scramble.\n";
            return;
    }

    if (game) {
        game->setWords();
        game->playGame();
        delete game;
    }
}
