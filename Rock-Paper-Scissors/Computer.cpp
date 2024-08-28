#include "Computer.h"

Computer::Computer(){
    move = ' ';
}

void Computer::setMove(){
    move = 'R';
}

char Computer::getMove(){
    return move;
}