#ifndef GAME_H
#define GAME_H

#include <array>
#include <string>
#include "Bag.h"
#include "Board.h"
#include "Player.h"
#include "Move.h"

class Game {
    Bag bag_;
    Board board_;
    std::array<Player, 2> players_;
    int current_player_;
public:
    Game(std::string p1, std::string p2);
    void nextTurn();
    Player& getCurrentPlayer();
    Board& getBoard();
    bool isOver();
    std::string applyMove(const Move& move); // "" on success, error message otherwise
};

#endif
