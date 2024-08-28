#include "Avalanche.h"

Avalanche::Avalanche(){
    move = ' ';
}

void Avalanche::setMove(){
    move = 'R';
}

char Avalanche::getMove(){
    return move;
}