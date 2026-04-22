#include "../include/Game.h"
#include <algorithm>
#include <cctype>

Game::Game(std::string p1, std::string p2)
    : players_{{Player(p1), Player(p2)}}, current_player_(0)
{
    players_[0].drawFromBag(bag_);
    players_[1].drawFromBag(bag_);
}

void Game::nextTurn() {
    current_player_ = 1 - current_player_;
}

Player& Game::getCurrentPlayer() {
    return players_[current_player_];
}

Board& Game::getBoard() {
    return board_;
}

bool Game::isOver() {
    return bag_.isEmpty();
}

std::string Game::applyMove(const Move& move) {
    Player& player = getCurrentPlayer();
    std::vector<Piece>& hand = player.getHand();

    // Track which hand slots are consumed during validation so we don't
    // double-count (e.g. word "AA" with only one 'A' in hand).
    std::vector<bool> consumed(hand.size(), false);

    for (int i = 0; i < static_cast<int>(move.word.size()); i++) {
        char ch   = move.word[i];
        char needed   = static_cast<char>(std::toupper((unsigned char)ch));
        bool use_blank = std::islower((unsigned char)ch);

        int r = move.row + (move.horizontal ? 0 : i);
        int c = move.col + (move.horizontal ? i : 0);

        if (board_.isOccupied(r, c)) {
            char on_board = board_.getTile(r, c).piece->getLetter();
            if (on_board != needed)
                return std::string("conflict at square (") + std::to_string(r) + "," +
                       std::to_string(c) + "): board has '" + on_board +
                       "', word requires '" + needed + "'";
        } else {
            bool found = false;
            for (size_t j = 0; j < hand.size(); j++) {
                if (consumed[j]) continue;
                bool matches = use_blank ? hand[j].isWildcard()
                                         : hand[j].getLetter() == needed;
                if (matches) { consumed[j] = true; found = true; break; }
            }
            if (!found)
                return use_blank ? std::string("no blank tile in hand")
                                 : std::string("'") + needed + "' not in hand";
        }
    }

    // Validation passed — place tiles in reverse index order so erasing doesn't
    // shift indices we haven't processed yet.
    std::vector<int> to_erase;
    for (int i = 0; i < static_cast<int>(move.word.size()); i++) {
        char ch      = move.word[i];
        char needed  = static_cast<char>(std::toupper((unsigned char)ch));
        bool use_blank = std::islower((unsigned char)ch);

        int r = move.row + (move.horizontal ? 0 : i);
        int c = move.col + (move.horizontal ? i : 0);

        if (!board_.isOccupied(r, c)) {
            for (size_t j = 0; j < hand.size(); j++) {
                bool matches = use_blank ? hand[j].isWildcard()
                                         : hand[j].getLetter() == needed;
                if (matches && std::find(to_erase.begin(), to_erase.end(), (int)j) == to_erase.end()) {
                    if (use_blank) hand[j].setLetter(needed);
                    board_.placePiece(r, c, hand[j]);
                    to_erase.push_back(static_cast<int>(j));
                    break;
                }
            }
        }
    }

    std::sort(to_erase.rbegin(), to_erase.rend());
    for (int idx : to_erase)
        hand.erase(hand.begin() + idx);

    player.drawFromBag(bag_);
    return "";
}
