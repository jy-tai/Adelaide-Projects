#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player{
    public:
        Human();
        void setMove();
        char getMove();
        ~Human(){};
    private:
        char move;
};
#endif
