function [deck,profile] = drawCards (player, deck, profile)
% draw 2 cards for each player

for n = 1:player
    for m = 1:2
        profile(n,m+1) = deck(1,1);
        deck(1,:) = [];
    end
end

% update the deck
deck = deck;
end