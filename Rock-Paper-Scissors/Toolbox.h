#ifndef TOOLBOX_H
#define TOOLBOX_H

#include "Computer.h"

class Toolbox : public Computer{
    public:
        Toolbox();
        void setMove();
        char getMove();
        ~Toolbox(){};
    private:
        char move;
};
#endif