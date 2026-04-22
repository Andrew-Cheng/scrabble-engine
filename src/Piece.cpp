#include "../include/Piece.h"

//constructor for piece
Piece::Piece(char letter, std::uint32_t value)
: letter_(letter), value_(value), is_wildcard_(false)
{
    if (letter_ == '_'){
        is_wildcard_ = true;
    }
}

//get value of piece
std::uint32_t Piece::getValue() const {
    return value_;
}
char Piece::getLetter() const {
    return letter_;
}

//set letter (for wildcards)
void Piece::setLetter(char letter){
    letter_ = letter;
}

bool Piece::isWildcard() const {
    return is_wildcard_;
}
