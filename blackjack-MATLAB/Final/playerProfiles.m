function [players] = playerProfiles(numPlayers)
    % create and return profile for each player base on numPlayers
    players = cell(numPlayers,1);   % create cell array
    
    for n = [1:numPlayers]
        players{n} = "Player"+n;
    end
end