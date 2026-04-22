#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <cstdint>
#include "Piece.h"
#include "Bag.h"

class Player {
    std::string name_;
    std::vector<Piece> hand_;
    uint32_t score_;
public:
    Player(std::string name);
    void drawFromBag(Bag& bag);   // draw up to fill hand to 7 pieces
    void addScore(uint32_t points);
    uint32_t getScore();
    std::string getName();
    std::vector<Piece>& getHand();
    void printHand();
};
#endif
