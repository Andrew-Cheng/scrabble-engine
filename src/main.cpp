#include <iostream>
#include <vector>
#include "../include/Bag.h"
#include "../include/Piece.h"

int main(int argc, char** argv) {
    Bag bag = Bag();
    std::vector<Piece> chicken = bag.drawPieces(5);
    for (Piece p : chicken){
        std::cout << p.getLetter() << " : " << p.getValue() << "\n";
    }
    // bag.printBag();
    return 0;
}