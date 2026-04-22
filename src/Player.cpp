#include "../include/Player.h"
#include <iostream>

Player::Player(std::string name)
: name_{name}, hand_{}, score_{0}
{
}

void Player::drawFromBag(Bag& bag){
    uint32_t needed = 7 - hand_.size();
    std::vector<Piece> drawn = bag.drawPieces(needed);
    for (Piece p : drawn){
        hand_.push_back(p);
    }
}

void Player::addScore(uint32_t points){
    score_ += points;
}

uint32_t Player::getScore(){
    return score_;
}

std::string Player::getName(){
    return name_;
}

std::vector<Piece>& Player::getHand(){
    return hand_;
}

void Player::printHand(){
    for (Piece p : hand_){
        std::cout << p.getLetter() << " : " << p.getValue() << "\n";
    }
}
