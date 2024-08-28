# include "Crescendo.h"

Crescendo::Crescendo(){
    count1 = 0;
    count2 = 0;
    move = ' ';
}

void Crescendo::setMove(){
    switch (count1){
        case 0:
            move = 'P';
            break;
        case 1:
            move = 'S';
            break;
        case 2:
            move = 'R';
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

char Crescendo::getMove(){
    return move;
}