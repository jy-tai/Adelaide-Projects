#include "Human.h"
#include <iostream>

Human::Human(){
    move = ' ';
}

void Human::setMove(){
    std::cout << "Enter move: ";
    std::cin >> move;
}

char Human::getMove(){
    return move;
}