#ifndef BAG_H
#define BAG_H

#include <set>
#include <vector>
#include <random>
#include "Piece.h"
class Bag {
    private: 
        std::multiset<Piece> bag_;
        std::mt19937 mt;
    public: 
        Bag();
        std::vector<Piece> drawPieces(int count);
        bool isEmpty();
        void printBag();
};
#endif