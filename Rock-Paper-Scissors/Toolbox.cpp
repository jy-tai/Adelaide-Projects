#include "Toolbox.h"

Toolbox::Toolbox(){
    move = ' ';
}

void Toolbox::setMove(){
    move = 'S';
}

char Toolbox::getMove(){
    return move;
}