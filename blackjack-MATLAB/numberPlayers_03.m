function [numPlayers,players] = numberPlayers_03()
    % prompt for number of players and create profile for each
    numPlayers = 0;
    while numPlayers < 2 || numPlayers > 10
        numPlayers = input('Enter the number of players (2-10): ');
    end
    
    players = cell(numPlayers,1);
    for n = [1:numPlayers]
        players{n} = "Player"+n;
    end
end