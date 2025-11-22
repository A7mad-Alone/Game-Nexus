// By A7mad_Alone
// AKA Ahmad Adham
#ifndef RPS_H
#define RPS_H
#include <bits/stdc++.h>
#include "Games.h"
using namespace std;
//V1.0
//==================================
//RPS.h Library Contents (Declaration).
//2.Rock Paper Scissors.
//==================================
namespace Games {
    class RPS : public templateGame {
        protected:
            string playerChoice, computerChoice;
            int playerInput, randomChoice;
            void RPSComputerChoice();
            void RPSPlayerChoice();
            void RPSWinner();
            // RPS() : templateGame(2, "Rock Paper Scissors") {};
        public:
            void RPSStart();
    };
}
#endif