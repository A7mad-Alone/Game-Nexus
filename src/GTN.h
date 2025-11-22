// By A7mad_Alone
// AKA Ahmad Adham
#ifndef GTN_H
#define GTN_H
#include <bits/stdc++.h>
#include "Games.h"
using namespace std;
//V1.0
//==================================
//GTN.h Library Contents (Declaration).
//3.Guess The Number.
//==================================
namespace Games {
    class GTN : public templateGame {
        protected:
            int range, randomNumber, attempts;
            void GTNGameRange();
            void GTNPlay();
            
        public:
            // GTN() : templateGame(3, "Guess The Number") {}
            void GTNStart();
    };
}
#endif