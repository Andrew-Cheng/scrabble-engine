#ifndef BOARD_H
#define BOARD_H

#include <optional>
#include "Piece.h"

enum class Multiplier { NONE, DL, TL, DW, TW };

struct Tile {
    std::optional<Piece> piece;
    Multiplier mult;
};

class Board {
    private:
        Tile grid_[15][15];
    public:
        Board();
        void placePiece(int row, int col, Piece p);
        bool isOccupied(int row, int col);
        Tile& getTile(int row, int col);
        void printBoard();
};

#endif
