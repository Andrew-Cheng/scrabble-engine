#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <optional>

struct Move {
    int row;
    int col;
    bool horizontal;
    std::string word;
};

std::pair<std::optional<Move>, std::string> parseMove(const std::string& input);
#endif
