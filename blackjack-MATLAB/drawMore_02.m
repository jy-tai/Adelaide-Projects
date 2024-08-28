function [profile] = drawMore_02(numPlayers, profile, deck_2)
% prompt for more draws (third or more draws)

    for n = 1:numPlayers
        hands = profile{n,2};
        card = sort(hands);     % arrange the cards in ascending order

        fprintf ("%s's turn\n",profile{n,1});
        fprintf ("Your cards are: %s, ",card(1:end-1));
        fprintf ("%s\nDo you want to draw more? (Yes/No) \n", card(end));
        choice = input ("", 's');

        while ( (choice == "yes" || choice == "Yes") && (length(profile{n,2}) <= 11)) && points <= 21
               % maximum cards in hand is 11, for points to not excedd 21.
               % {A,A,A,A,2,2,2,2,3,3,3}
                hands(end+1) = deck_2(1,1);
                deck_2(1,:) = [];
                card = sort(hands); % arrange in ascending order
                
                if choice 
                fprintf ("Your cards are: ");
                fprintf ("%s, ",card(1:end-1));
                fprintf ("%s\nDo you want to draw more? (Yes/No) \n",card(end));
                choice = input ("", 's');
        end
        profile(n,2) = {hands};
        clc;
    end
end