#include "RandomComputer.h"
#include <stdlib.h>
//#include <time.h>

//srand(time(NULL));

RandomComputer::RandomComputer(){
    cmove = ' ';
}

void RandomComputer::setMove(){
    imove = rand()%3;
    switch (imove){
        case 0:
            cmove = 'R';
            break;
        case 1:
            cmove = 'p';
            break;
        case 2:
            cmove = 'S';
            break;
    }
}

char RandomComputer::getMove(){
    return cmove;
}