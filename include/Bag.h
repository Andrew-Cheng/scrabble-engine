#ifndef BAG_H
#define BAG_H

#include <vector>
#include <random>
#include <cstdint>
#include "Piece.h"

class Bag {
    public: 
        struct tile;
    private: 
        std::vector<Piece> bag_;
    public: 
        Bag();
        std::vector<Piece> drawPieces(std::uint32_t count);
        bool isEmpty();
        void printBag();
};
#endif