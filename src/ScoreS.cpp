// By A7mad_Alone
// AKA Ahmad Adham
#include "ScoreS.h"
#include <bits/stdc++.h>
#include "Utilities.h"
#include "Games.h"
using namespace std;
using namespace Utilities;
using namespace Games;
//using namespace Score;
//V1.0
//==================================
//GTN.cpp Code Contents (Actual Functions Code).
//3.Guess The Number.
//==================================
//namespace Score {
    void ScoreSystem::coinFlipScoreS () {
        do {
            CoinStart();
            (CoinFlip::playerInput == CoinFlip::randomChoice) ? winStreak = 0 : winStreak++;
            score = winStreak;
            cout << "Your Current Score/Winstreak is: " << score << endl; //TODO Whenever The Player reaches a winstreak of 5 it gets saved into the points system.
            conti();
        } while (true);
    }
    void ScoreSystem::RPSScoreS () {
        do {        
            RPSStart();
            if (((playerChoice == "Rock" && computerChoice == "Scissors") || (playerChoice == "Scissors" && computerChoice == "Paper") || (playerChoice == "Paper" && computerChoice == "Rock"))) winStreak++;
            else if (playerChoice != computerChoice) winStreak = 0;
            score = winStreak;
            cout << "Your Current Score/Winstreak is: " << score << endl; //TODO Whenever The Player reaches a winstreak of 3 it gets saved into the points system.
            conti();
        } while (true);
    }
    void ScoreSystem::GTNScoreS () {
        do {
            GTNStart();
            if (attempts == 1) score = 6;
            else if (attempts == 2) score = 5; 
            else if (attempts > 2 && attempts <= 6) score = 4; 
            else if (attempts > 6 && attempts <= 10) score = 2; 
            else score = 1;
            //TODO Difficulity System: Easy:1, Med:2, Hard:3, Nightmare:5.
            //TODO attempts + difficulity = score
            cout << "Your Score is: " << score << endl;
            conti();
        } while (true);
    }
    
    
//}