#ifndef Player_H
#define Player_H

class Player{
    public:
        Player();
        virtual void setMove();
        virtual char getMove();
        ~Player(){};
    private:
        char move;
};
#endif
