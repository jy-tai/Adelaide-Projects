function [profilePlayers] = numberPlayers (number)
% prompt for number of players and create profile for each

% fprintf('Enter the number of players: %d', n);
% input(n);

profilePlayers = [];
for i = [1:number]
    profilePlayers = [profilePlayers; i];
end
end