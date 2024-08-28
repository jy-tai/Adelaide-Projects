#include "FistfullODollars.h"

FistfullODollars::FistfullODollars(){
    count1 = 0;
    count2 = 0;
    move = ' ';
}

void FistfullODollars::setMove(){
    switch (count1){
        case 0:
            move = 'R';
            break;
        case 1:
            move = 'P';
            break;
        case 2:
            move = 'P';
            break;
    }
    if (count1 == 2){
        count1 = 0;
    } else {
        count1++;
    }
    if (count2 == 4){
        count2 = 0;
    } else {
        count2++;
    }
}

char FistfullODollars::getMove(){
    return move;
}