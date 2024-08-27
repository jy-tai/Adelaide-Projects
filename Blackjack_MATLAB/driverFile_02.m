% function [card_combinations] = drawCards (number)


% the number of players
[numPlayers, profiles] = numberPlayers_03;

% values of each cards
% [value] = value();

% the deck
deck = createDeck;
% shuffle the deck
% shuffled = shuffle_02(deck);

% draw two cards each
[deck_2, profiles] = drawCards_03(numPlayers, profiles, deck);

% make choice for more draws
profiles = drawMore(numPlayers, profiles, deck_2);

% calculate points
[playerPoints,cards, numA] = points_02(numPlayers, profiles);

% determine winner
% [playerN] = winner(numPlayers,playerPoints);