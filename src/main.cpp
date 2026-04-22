#include <iostream>
#include <string>
#include "../include/Game.h"
#include "../include/Move.h"

int main() {
    Game game("Player1", "Player2");
    while (!game.isOver()) {
        game.getBoard().printBoard();
        Player& current = game.getCurrentPlayer();
        std::cout << "\n" << current.getName() << "'s hand: ";
        current.printHand();
        std::cout << "Move (e.g. H8 CRANE): ";

        std::string line;
        if (!std::getline(std::cin, line)) break;

        auto [move_opt, parse_err] = parseMove(line);
        if (!move_opt) {
            std::cout << "Invalid: " << parse_err << "\n\n";
            continue;
        }

        std::string apply_err = game.applyMove(*move_opt);
        if (!apply_err.empty()) {
            std::cout << "Invalid: " << apply_err << "\n\n";
            continue;
        }

        game.nextTurn();
    }
    std::cout << "Game over!\n";
    return 0;
}
