#include "Computer.h"
#include "Human.h"
#include "Referee.h"

#include <iostream>
using namespace std;

int main(){
    Human player1;
    Computer player2;

    player1.setMove();
    player2.setMove();

    Referee ref1;
    cout << ref1.refGame(player1, player2) << endl;


    return 0;
}
