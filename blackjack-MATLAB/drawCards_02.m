function [deck2,profile] = drawCards_02 (numPlayers, profile, shuffledDeck)
% draw 2 cards for each player

deck2 = shuffledDeck;   % create copy of deck to update after the draws
for n = 1:numPlayers
    hand = [];
    for m = 1:2     % draw two cards
        hand(n,m) = deck2(1,1);
        deck2(1,:) = [];
    end
    profile(n,2) = {hand(n,:)};
end
end