#ifndef AVALANCHE_H
#define AVALANCHE_H

#include "Computer.h"

class Avalanche : public Computer{
    public:
        Avalanche();
        void setMove();
        char getMove();
        ~Avalanche(){};
    private:
        char move;
};
#endif