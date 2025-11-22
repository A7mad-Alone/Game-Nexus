// By A7mad_Alone
// AKA Ahmad Adham
#ifndef COINFLIP_H
#define COINFLIP_H
#include <bits/stdc++.h>
#include "Games.h"
using namespace std;
//V1.0
//==================================
//CoinFlip.h Library Contents (Declaration).
//1.Coin Flip.
//==================================
namespace Games {
    class CoinFlip : public templateGame {
        protected:
            int playerInput, randomChoice;
            void CoinComputerChoice();
            void CoinPlayerChoice();
            void CoinWinner();
            //CoinFlip() : templateGame(1, "Coin Flip") {};
        public:
            void CoinStart();
            
    };
}
#endif