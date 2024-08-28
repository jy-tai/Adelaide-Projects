#ifndef FISTFULLODOLLARS_H
#define FISTFULLODOLLARS_H

#include "Computer.h"

class FistfullODollars : public Computer{
    public:
        FistfullODollars();
        void setMove();
        char getMove();
        ~FistfullODollars(){};
    private:
        int count1;     // for 3 moves repetition
        int count2;     // for resetting after a tournament 'round'
        char move;
};
#endif