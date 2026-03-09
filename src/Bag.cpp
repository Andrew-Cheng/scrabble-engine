#include "../include/Bag.h"
#include "../include/Piece.h"
#include <iostream>
#include <iterator>
#include <algorithm> 

Bag::Bag()
: bag_{{
        // Blanks
        Piece('_', 0), Piece('_', 0), Piece('_', 0),
        // A-E
        Piece('A', 1), Piece('A', 1), Piece('A', 1), Piece('A', 1), Piece('A', 1), Piece('A', 1), Piece('A', 1), Piece('A', 1), Piece('A', 1),
        Piece('B', 4), Piece('B', 4),
        Piece('C', 3), Piece('C', 3),
        Piece('D', 2), Piece('D', 2), Piece('D', 2), Piece('D', 2),
        Piece('E', 1), Piece('E', 1), Piece('E', 1), Piece('E', 1), Piece('E', 1), Piece('E', 1),
        Piece('E', 1), Piece('E', 1), Piece('E', 1), Piece('E', 1), Piece('E', 1), Piece('E', 1),
        // F-J
        Piece('F', 4), Piece('F', 4),
        Piece('G', 4), Piece('G', 4), Piece('G', 4),
        Piece('H', 3), Piece('H', 3), Piece('H', 3),
        Piece('I', 1), Piece('I', 1), Piece('I', 1), Piece('I', 1), Piece('I', 1), Piece('I', 1), Piece('I', 1), Piece('I', 1),
        Piece('J', 10),
        // K-O
        Piece('K', 6),
        Piece('L', 2), Piece('L', 2), Piece('L', 2), Piece('L', 2),
        Piece('M', 3), Piece('M', 3),
        Piece('N', 1), Piece('N', 1), Piece('N', 1), Piece('N', 1), Piece('N', 1),
        Piece('O', 1), Piece('O', 1), Piece('O', 1), Piece('O', 1), Piece('O', 1), Piece('O', 1), Piece('O', 1), Piece('O', 1),
        // P-T
        Piece('P', 3), Piece('P', 3),
        Piece('Q', 10),
        Piece('R', 1), Piece('R', 1), Piece('R', 1), Piece('R', 1), Piece('R', 1), Piece('R', 1),
        Piece('S', 1), Piece('S', 1), Piece('S', 1), Piece('S', 1), Piece('S', 1),
        Piece('T', 1), Piece('T', 1), Piece('T', 1), Piece('T', 1), Piece('T', 1), Piece('T', 1),
        // U-Z
        Piece('U', 2), Piece('U', 2), Piece('U', 2),
        Piece('V', 6), Piece('V', 6),
        Piece('W', 5), Piece('W', 5),
        Piece('X', 8),
        Piece('Y', 4), Piece('Y', 4),
        Piece('Z', 10),
    }}, 
    mt{std::random_device{}()}
{
    std::shuffle(bag_.begin(), bag_.end(), mt);
}

std::vector<Piece> Bag::drawPieces(std::uint32_t count){
    std::vector<Piece> drawnPieces = {}; 
    for (uint8_t i = 0; i < std::min(count, (std::uint32_t)bag_.size()); i++){
        drawnPieces.push_back(bag_.back());
        bag_.pop_back();
    }
    return drawnPieces;
}
bool Bag::isEmpty(){
    return bag_.empty();
}
void Bag::printBag(){
    for (Piece p : bag_){
        std::cout << p.getLetter() << " : " << p.getValue() << "\n";
    }
}