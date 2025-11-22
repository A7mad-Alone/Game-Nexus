#ifndef NUMBER_MEMORY_H
#define NUMBER_MEMORY_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <limits>
#include <cstdlib> // For system("cls") or system("clear")

void clearScreen();

class MemoryGame {
private:
    std::vector<int> numbers;
    int level;
    int attempts;

public:
    MemoryGame();
    void generateNumbers();
    void showNumbers();
    bool getUserInput();
    void play();
};

void playNumberMemory();

#endif // NUMBER_MEMORY_H