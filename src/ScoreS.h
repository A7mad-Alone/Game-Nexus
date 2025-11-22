// By A7mad_Alone
// AKA Ahmad Adham
#ifndef ScoreS_H
#define ScoreS_H
#include <bits/stdc++.h>
#include "Games.h"
using namespace Games;
//V1.0
//==================================
//Menus.h Library Contents (Declaration).
//1.Main Menu Function.
//==================================
//namespace Score {
    class ScoreSystem : protected RPS, protected GTN, protected CoinFlip {
        public:
            int winStreak = 0;
            int score = 0;
            void coinFlipScoreS ();
            void RPSScoreS ();
            void GTNScoreS ();
    };
//}
#endif 