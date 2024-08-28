#ifndef CRESCENDO_H
#define CRESCENDO_H

#include "Computer.h"

class Crescendo : public Computer{
    public:
        Crescendo();
        void setMove();
        char getMove();
        ~Crescendo(){};
    private:
        int count1;     // for 3 moves repetition
        int count2;     // for resetting after a tournament 'round'
        char move;
};
#endif