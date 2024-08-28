function [points] = drawMore_03(numPlayers, profile, deck_2)
% prompt for more draws (third or more draws)

    for n = 1:numPlayers
        hands = profile{n,2};
        card = sort(hands);     % arrange the cards in ascending order
        
        score = points_02(card);    % calculate initial score
        
        fprintf ("%s's turn\n",profile{n,1});
        
        choice = "yes";
        while (choice == "yes") && (length(profile{n,2}) <= 11) && (score <= 21)
            % maximum cards in hand is 11, for points to not excedd 21.
            % {A,A,A,A,2,2,2,2,3,3,3}
            
            fprintf ("Your cards are: ");
            fprintf ("%s, ",card(1:end-1));
            fprintf ("%s\n",card(end));
            choice = lower(input ("Do you want to draw more? (Yes/No) ", 's'));
            
            while ~( choice == "yes" || choice == "no" )
                choice = lower(input ("Do you want to draw more? (Yes/No)", 's'));
            end
            
            if choice == "no"
                % points final
                break
            end
            hands(end+1) = deck_2(1,1);
            deck_2(1,:) = [];
            card = sort(hands); % arrange in ascending order
            
            % call function points
            score = points_02(card);
        end
        points(n,1) = n;
        points(n,2) = score;
        input("Press any key for next Player:")
        clc;
    end
end