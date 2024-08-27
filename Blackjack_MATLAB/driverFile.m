% function [card_combinations] = drawCards (number)


% the number of players
n = input('Enter the number of players: ');
profiles = numberPlayers_03();
%

% shuffle the deck
deck_1 = shuffleDeck();

% draw two cards each
[deck_2, profiles] = drawCards_02(n, deck_1, profiles);

% make choice for more draws


% calculate points


% determine winner