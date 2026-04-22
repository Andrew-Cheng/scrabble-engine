#include "../include/Move.h"
#include <sstream>
#include <cctype>
#include <stdexcept>

std::pair<std::optional<Move>, std::string> parseMove(const std::string& input) {
    std::istringstream iss(input);
    std::string pos, word;
    if (!(iss >> pos >> word) || word.empty())
        return {std::nullopt, "expected: <position> <word>  e.g. H8 CRANE or 8H CRANE"};

    Move move;
    move.word = word;

    if (std::isalpha((unsigned char)pos[0])) {
        // Letter-first = horizontal: e.g. H8
        move.horizontal = true;
        char row_char = std::toupper((unsigned char)pos[0]);
        if (row_char < 'A' || row_char > 'O')
            return {std::nullopt, "row letter must be A-O"};
        move.row = row_char - 'A';
        try { move.col = std::stoi(pos.substr(1)) - 1; }
        catch (...) { return {std::nullopt, "invalid column number"}; }
    } else {
        // Digit-first = vertical: e.g. 8H
        move.horizontal = false;
        size_t i = 0;
        std::string num_part;
        while (i < pos.size() && std::isdigit((unsigned char)pos[i]))
            num_part += pos[i++];
        if (i >= pos.size() || !std::isalpha((unsigned char)pos[i]))
            return {std::nullopt, "invalid position format"};
        char col_char = std::toupper((unsigned char)pos[i]);
        if (col_char < 'A' || col_char > 'O')
            return {std::nullopt, "column letter must be A-O"};
        move.col = col_char - 'A';
        try { move.row = std::stoi(num_part) - 1; }
        catch (...) { return {std::nullopt, "invalid row number"}; }
    }

    if (move.row < 0 || move.row > 14 || move.col < 0 || move.col > 14)
        return {std::nullopt, "position out of bounds (rows A-O, cols 1-15)"};

    int len = static_cast<int>(word.size());
    if (move.horizontal && move.col + len > 15)
        return {std::nullopt, "word extends off right edge of board"};
    if (!move.horizontal && move.row + len > 15)
        return {std::nullopt, "word extends off bottom of board"};

    return {move, ""};
}
