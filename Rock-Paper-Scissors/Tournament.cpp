#include "Tournament.h"

Tournament::Tournament(){

}

// run tournament 
Player * Tournament::run(std::array<Player*,8> competitors){
    player_id = 0;
    semi_count = 0;

    // first four games
    for (int i = 0; i < 4; i++){
        win_count = 0;
        lose_count = 0;
        // games of 2 players, 5 rounds
        for (int j = 0; j < 5; j++){
            outcome = refGame(competitors.at(player_id), competitors.at(player_id+1));
            // counts wins and losses
            switch (outcome){
                case 'W':
                    win_count++;
                    break;
                case 'L':
                    lose_count++;
                    break;
            }
        }
        if (win_count >= lose_count){
            semilists.at(semi_count) = competitors.at(player_id);
            semi_count++;
        } else {
            semilists.at(semi_count) = competitors.at(player_id+1);
            semi_count++;
        }

        if (player_id < 6){
            player_id+=2;
        }
    }

    player_id = 0;
    final_count = 0;

    // semifinal games
    for (int i = 0; i < 2; i++){
        win_count = 0;
        lose_count = 0;
        // games of 2 players, 5 rounds
        for (int j = 0; j < 5; j++){

            outcome = refGame(semilists.at(player_id), semilists.at(player_id+1));
            // counts wins and losses
            switch (outcome){
                case 'W':
                    win_count++;
                    break;
                case 'L':
                    lose_count++;
                    break;
            }
        }

        if (win_count >= lose_count){
            finalists.at(final_count) = semilists.at(player_id);
            final_count++;
        } else {
            finalists.at(final_count) = semilists.at(player_id+1);
            final_count++;
        }
        
        if (player_id < 2){
            player_id+=2;
        }
    }


    // finals

    player_id = 0;

    win_count = 0;
    lose_count = 0;
    // games of 2 players, 5 rounds
    for (int j = 0; j < 5; j++){
        outcome = refGame(finalists.at(player_id), finalists.at(player_id+1));
        // counts wins and losses
        switch (outcome){
            case 'W':
                win_count++;
                break;
            case 'L':
                lose_count++;
                break;
        }
    }
    if (win_count >= lose_count){
        winner = finalists.at(player_id);
    } else {
        winner = finalists.at(player_id+1);
    }

    // declares winner
    return winner;
}