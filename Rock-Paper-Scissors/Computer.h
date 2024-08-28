#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player{
    public:
        Computer();
        virtual void setMove();
        virtual char getMove();
        ~Computer(){};
    private:
        char move;
};
#endif
