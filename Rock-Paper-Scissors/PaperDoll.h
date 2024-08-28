#ifndef PAPERDOLL_H
#define PAPERDOLL_H

#include "Computer.h"

class PaperDoll : public Computer{
    public:
        PaperDoll();
        void setMove();
        char getMove();
        ~PaperDoll(){};
    private:
        int count1;     // for 3 moves repetition
        int count2;     // for resetting after a tournament 'round'
        char move;
};
#endif