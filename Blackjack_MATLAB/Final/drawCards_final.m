function [deck2,profile] = drawCards_final (numPlayers, profile, shuffledDeck)
% draw initial 2 cards for numPlayers from the shuffledDeck
% and update and return profiles
% return remaning deck

    deck2 = shuffledDeck;   % create copy of deck to update after the draws
    for n = 1:numPlayers
        hand = [];
        for m = 1:2     % loop twice to draw two cards
            hand = [hand deck2(1,1)];
            deck2(1,:) = [];    % remove the card from deck after withdrawal
        end
        profile(n,2) = {hand};  % update profile
    end
end