#include "Player.h"
#include "Referee.h"
#include <iostream>


Referee::Referee(){

}

char Referee::refGame(Player *player1, Player *player2){
    player1->setMove();
    player2->setMove();
    move1 = player1->getMove();
    move2 = player2->getMove();
    
    if (move1 == move2){                    // same moves
        result = 'T';
    } else if (move1=='R' && move2=='P')     // rock vs paper
    {
        result = 'L';
    } else if (move1=='R' && move2=='S')     // rock vs scissors
    {
        result = 'W';
    } else if (move1=='P' && move2=='R')     // paper vs rock
    {
        result = 'W';
    } else if (move1=='P' && move2=='S')     // paper vs scissors
    {
        result = 'L';
    } else if (move1=='S' && move2=='R')     // scissors vs rock
    {
        result = 'L';
    } else if (move1=='S' && move2=='P')     // scissors vs paper
    {
        result = 'W';
    }
    
    return result;
}