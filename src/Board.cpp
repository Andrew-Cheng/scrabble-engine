#include "../include/Board.h"
#include <iostream>

Board::Board() {
    // Initialize all tiles to NONE multiplier with no piece
    for (int r = 0; r < 15; r++) {
        for (int c = 0; c < 15; c++) {
            grid_[r][c].piece = std::nullopt;
            grid_[r][c].mult = Multiplier::NONE;
        }
    }

    // Triple Word (TW)
    const int tw[][2] = {
        {0,0}, {0,7}, {0,14},
        {7,0},        {7,14},
        {14,0},{14,7},{14,14}
    };
    for (auto& pos : tw) {
        grid_[pos[0]][pos[1]].mult = Multiplier::TW;
    }

    // Double Word (DW)
    const int dw[][2] = {
        {1,1},  {2,2},  {3,3},  {4,4},
        {1,13}, {2,12}, {3,11}, {4,10},
        {7,7},
        {10,4}, {11,3}, {12,2}, {13,1},
        {10,10},{11,11},{12,12},{13,13}
    };
    for (auto& pos : dw) {
        grid_[pos[0]][pos[1]].mult = Multiplier::DW;
    }

    // Triple Letter (TL)
    const int tl[][2] = {
        {1,5},  {1,9},
        {5,1},  {5,5},  {5,9},  {5,13},
        {9,1},  {9,5},  {9,9},  {9,13},
        {13,5}, {13,9}
    };
    for (auto& pos : tl) {
        grid_[pos[0]][pos[1]].mult = Multiplier::TL;
    }

    // Double Letter (DL)
    const int dl[][2] = {
        {0,3},  {0,11},
        {2,6},  {2,8},
        {3,0},  {3,7},  {3,14},
        {6,2},  {6,6},  {6,8},  {6,12},
        {7,3},  {7,11},
        {8,2},  {8,6},  {8,8},  {8,12},
        {11,0}, {11,7}, {11,14},
        {12,6}, {12,8},
        {14,3}, {14,11}
    };
    for (auto& pos : dl) {
        grid_[pos[0]][pos[1]].mult = Multiplier::DL;
    }
}

void Board::placePiece(int row, int col, Piece p) {
    grid_[row][col].piece = p;
}

bool Board::isOccupied(int row, int col) {
    return grid_[row][col].piece.has_value();
}

Tile& Board::getTile(int row, int col) {
    return grid_[row][col];
}

void Board::printBoard() {
    // Column header
    std::cout << "   ";
    for (int c = 0; c < 15; c++) {
        std::cout << (c < 10 ? " " : "") << c << " ";
    }
    std::cout << "\n";

    for (int r = 0; r < 15; r++) {
        // Row header
        std::cout << (r < 10 ? " " : "") << r << " ";

        for (int c = 0; c < 15; c++) {
            const Tile& t = grid_[r][c];
            if (t.piece.has_value()) {
                std::cout << t.piece->getLetter() << "  ";
            } else {
                switch (t.mult) {
                    case Multiplier::TW:   std::cout << "TW "; break;
                    case Multiplier::DW:   std::cout << "DW "; break;
                    case Multiplier::TL:   std::cout << "TL "; break;
                    case Multiplier::DL:   std::cout << "DL "; break;
                    case Multiplier::NONE: std::cout << ".  "; break;
                }
            }
        }
        std::cout << "\n";
    }
}
