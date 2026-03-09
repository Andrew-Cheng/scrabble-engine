#include "Piece.h"

//constructor
Piece::Piece(char letter, std::uint8_t value)
: letter_(letter), value_(value), is_wildcard_(false)
{
    if (letter_ == '_'){
        is_wildcard_ = true;
    }
}

//getters
std::uint8_t Piece::getValue(){
    return value_;
}
char Piece::getLetter(){
    return letter_;
}

//setters
void Piece::setLetter(char letter){
    letter_ = letter;
}
