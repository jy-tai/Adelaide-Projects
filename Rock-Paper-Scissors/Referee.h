#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"

class Referee{
    public:
        Referee();
        char refGame(Player *player1, Player *player2); // player1, player2 move
    private:
        char move1; // player1 move
        char move2; // player 2 move
        char result;    // declare winner
};
#endif
