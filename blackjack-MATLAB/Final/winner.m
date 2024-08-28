function [] = winner(numPlayers,points)
% compare points between players annd prints the winner.
    for n = 1:numPlayers
        if points(n,2) > 21     % players with points>21 lose
            points(n,3) = 0;    % new column to sort out ranking
        else
            points(n,3) = points(n,2);  % copy the points over
        end
    end
    
    % arrange points from highest to lowest
    % use built-in function sortrows
    points = sortrows(points, [-3]);
    
    if points(1,3) == 0     % if first points=0; no winner
        fprintf("There is no winner!");
    else
        winner = [points(1,1)]; % if one or more players scores the same
        for i = 2:numPlayers    % highest points, they are winner..
            if points(i-1,3) == points(i,3)
                winner = [winner, points(i,1)];
            else
                break
            end
        end
        fprintf("Player%d wins!\n",winner);
    end
end
    
    
    
    
    
    
    
    
    
    
    
    
    