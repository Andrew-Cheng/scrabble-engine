#ifndef BAG_H
#define BAG_H

#include <vector>
#include <random>
#include <cstdint>
#include "Piece.h"
class Bag {
    private: 
        std::vector<Piece> bag_;
        std::mt19937 mt;
    public: 
        Bag();
        std::vector<Piece> drawPieces(std::uint32_t count);
        bool isEmpty();
        void printBag();
};
#endif