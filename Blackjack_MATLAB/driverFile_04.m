% the number of players
[numPlayers, profiles] = numberPlayers_03;

% the deck
deck = createDeck;

% shuffle the deck
shuffled = shuffle_02(deck);

% draw two cards for each player
[deck_2, profiles] = drawCards_03(numPlayers, profiles, shuffled);

% make choice for more draws and calculate points
points = drawMore_03(numPlayers, profiles, deck_2);

% determine winner
winner(numPlayers,points);