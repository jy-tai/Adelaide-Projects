#include "Referee.h"
#include <iostream>


Referee::Referee(){

}

char Referee::refGame(Human player1, Computer player2){
    move1 = player1.getMove();
    switch (move1){
        case 'R':
            result = 'T';
            break;
        case 'P':
            result = 'W';
            break;
        case 'S':
            result = 'L';
            break;
    }
    return result;
}
