#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Crescendo.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "RandomComputer.h"
#include "Toolbox.h"
#include "Referee.h"
#include "Tournament.h"

#include <array>
#include <iostream>
using namespace std;

int main(){
    // individual players
    Player *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
    Avalanche player1;
    Bureaucrat player2;
    Bureaucrat player3;
    Toolbox player4;
    Toolbox player5;
    Crescendo player6;
    Crescendo player7;
    FistfullODollars player8;
    p1 = &player1;
    p2 = &player2;
    p3 = &player3;
    p4 = &player4;
    p5 = &player5;
    p6 = &player6;
    p7 = &player7;
    p8 = &player8;
    // array of players
    array<Player*,8> players = {p1, p2, p3, p4, p5, p6, p7, p8};
    // tournament
    Tournament t1;
    // Tournament tournament;
    // t1 = &tournament;

    Player *winner = t1.run(players);
    cout << "The winner move is: " << winner->getMove() << endl;
    // cout << t1.run(players) << endl;

    return 0;
}