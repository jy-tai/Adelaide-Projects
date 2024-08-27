function [profile] = drawMore(numPlayers, profile, deck_2)
% prompt for more draws (third or more draws)

for n = 1:numPlayers
    hands = profile{n,2};
    fprintf ("%s's turn\nDo you want to draw? (Yes/No) \n", profile{n,1});
    choice = input ("", 's');
    while ( (choice == "yes" || choice == "Yes") && (length(profile{n,2}) < 11))
           % maximum cards in hand is 11, for points to not excedd 21.
           % {A,A,A,A,2,2,2,2,3,3,3}
            hands(end+1) = deck_2(1,1);
            deck_2(1,:) = [];
            fprintf ("Do you want another draw? (Yes/No) \n");
            choice = input ("", 's');
    end
    profile(n,2) = {hands};
end
end