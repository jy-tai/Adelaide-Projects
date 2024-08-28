#include "PaperDoll.h"

PaperDoll::PaperDoll(){
    count1 = 0;
    count2 = 0;
    move = ' ';
}

void PaperDoll::setMove(){
    switch(count1){
        case 0:
            move = 'P';
            break;
        case 1:
            move = 'S';
            break;
        case 2:
            move = 'S';
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

char PaperDoll::getMove(){
    return move;
}