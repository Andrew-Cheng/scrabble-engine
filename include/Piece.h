#ifndef PIECE_H
#define PIECE_H
#include <cstdint>


class Piece {
    private:
        char letter_;
        std::uint32_t value_;
        bool is_wildcard_;
    public: 
        Piece(char letter, std::uint32_t val);
        void setLetter(char letter);
        char getLetter();
        std::uint32_t getValue();
};
#endif