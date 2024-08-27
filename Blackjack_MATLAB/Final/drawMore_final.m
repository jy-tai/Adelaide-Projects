function [points] = drawMore_final(numPlayers, profile, deck_2)
% prompt for more draws (third or more draws) base on profile
% calculate and return the points for each player

    % loop through the number of players
    for n = 1:numPlayers
        hands = profile{n,2};   % cards of the nth player
        card = sort(hands);     % arrange the cards in ascending order
                                % 10,2,3,4,5,6,7,8,9,10,A,J,K,Q
        % sort is built-in matlab function
        
        score = points_final(card);    % calculate initial score
        
        fprintf ("%s's turn\n",profile{n,1});
        
        choice = "yes"; % initialise choice
        while (choice == "yes") && (score <= 21)
            fprintf ("Your cards are: ");   % prints cards in hand
            fprintf ("%s, ",card(1:end-1));
            fprintf ("%s\n",card(end));
            % prompt for user input 'yes' 'no' for further draws
            choice = lower(input ("Do you want to draw more? (Yes/No) ", 's'));
            
            % accept only 'yes','no' as input
            while ~( choice == "yes" || choice == "no" )
                choice = lower(input ("Do you want to draw more? (Yes/No)", 's'));
            end
            
            % stops drawing
            if choice == "no"
                break
            end
            
            hands(end+1) = deck_2(1,1); % update cards of nth player
            deck_2(1,:) = [];   % remove the card from deck after withdrawal
            card = sort(hands); % arrange in ascending order
            
            % call function points
            score = points_final(card); % update score after each draw
        end
        points(n,1) = n;        % create array to store score
        points(n,2) = score;    % store score in array points
        input("Press any key for next Player:",'s')
        clc;    % clear command window so that players can't see each others' cards
    end
end