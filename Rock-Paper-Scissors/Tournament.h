#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Player.h"
#include "Referee.h"
#include <array>

class Tournament : public Referee{
    public:
        Tournament();
        Player * run(std::array<Player*,8> competitors);    //whole tournament
        ~Tournament(){};
    private:
        std::array<Player*,8> competitors;
        Player *winner;
        char outcome;
        int player_id;
        int win_count;
        int lose_count;
        int semi_count;     // keep count of players getting to semifinals
        int final_count;    // keep count of players in finals
        std::array<Player*,4> semilists; // players that advanced to semi-finals
        std::array<Player*,2> finalists; // players that advanced to finals
        Referee *ref;
};
#endif