#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(){
    move = ' ';
}

void Bureaucrat::setMove(){
    move = 'P';
}


char Bureaucrat::getMove(){
    return move;
}