#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H

#include "Computer.h"

class RandomComputer : public Computer{
    public:
        RandomComputer();
        void setMove();
        char getMove();
        ~RandomComputer(){};
    private:
        int imove;
        char cmove;
};
#endif