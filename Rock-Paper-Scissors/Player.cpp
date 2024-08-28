#include "Player.h"
#include <iostream>

Player::Player(){
    move = ' ';
}

void Player::setMove(){
    std::cout << "Enter move: ";
    std::cin >> move;
}

char Player::getMove(){
    return move;
}