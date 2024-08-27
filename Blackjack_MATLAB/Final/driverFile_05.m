% the number of players
numPlayers = 0;
while numPlayers < 2 || numPlayers > 10
    numPlayers = input('Enter the number of players (2-10): ');
end
[profiles] = playerProfiles(numPlayers);

% the deck
deck = createDeck;

% shuffle the deck
shuffled = shuffle_final(deck);

% draw two cards for each player
[deck_2, profiles] = drawCards_final(numPlayers, profiles, shuffled);

% make choice for more draws and calculate points
points = drawMore_final(numPlayers, profiles, deck_2);

% determine winner
winner(numPlayers,points);