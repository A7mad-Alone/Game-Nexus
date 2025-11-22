// By A7mad_Alone
// AKA Ahmad Adham
#ifndef WordScramble_H
#define WordScramble_H
#include <bits/stdc++.h>
#include "Games.h"
using namespace Games;
//V1.0
//==================================
//Menus.h Library Contents (Declaration).
//1.Main Menu Function.
//==================================
class WordScrambleGame {
protected:
    vector<string> words;
    int score;
    int attempts;
    int positivePoints;
    int minusPoints;

public:
    void playGame();
    virtual void setWords() = 0;
    virtual int getPointsForCorrectAnswer() = 0;
    virtual int getPointsForWrongAnswer() = 0;
    int getAttempts() const;
    int getPositivePoints() const;
    int getMinusPoints() const;
    int getScore() const;
    virtual ~WordScrambleGame() {}
};

string scrambleWord(const string& word);
string toLowerCase(const string& str);


class EasyMode : public WordScrambleGame {
public:
    void setWords() override;
    int getPointsForCorrectAnswer() override;
    int getPointsForWrongAnswer() override;
};

class MediumMode : public WordScrambleGame {
public:
    void setWords() override;
    int getPointsForCorrectAnswer() override;
    int getPointsForWrongAnswer() override;
};

class HardMode : public WordScrambleGame {
public:
    void setWords() override;
    int getPointsForCorrectAnswer() override;
    int getPointsForWrongAnswer() override;
};

class ExtremeMode : public WordScrambleGame {
public:
    void setWords() override;
    int getPointsForCorrectAnswer() override;
    int getPointsForWrongAnswer() override;
};

class InsaneMode : public WordScrambleGame {
public:
    void setWords() override;
    int getPointsForCorrectAnswer() override;
    int getPointsForWrongAnswer() override;
};

int getDifficulty();

void playWordScramble();

#endif 