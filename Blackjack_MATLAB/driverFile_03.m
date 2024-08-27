% the number of players
[numPlayers, profiles] = numberPlayers_03;

% values of each cards
% [value] = value();

% the deck
deck = createDeck;

% shuffle the deck
shuffled = shuffle_02(deck);

% draw two cards each
[deck_2, profiles] = drawCards_03(numPlayers, profiles, shuffled);

% make choice for more draws
profiles = drawMore_02(numPlayers, profiles, deck_2);

% calculate points
[playerPoints] = points(numPlayers, profiles);

% determine winner
winner(numPlayers,playerPoints);