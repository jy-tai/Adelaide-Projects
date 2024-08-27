function [shuffledDeck] = shuffle_final(deck)
% perform shuffle on the deck

% generate 1:52 in random order
x = [];
for i = 1:length(deck)
    x(i) = randi([1,52],1);
    x = [x; x(i)];
    
    for j = 1:i-1
        while x(i)==x(j)
            x(i) = randi([1,52],1);
        end
    end
end

% assign relative rows of cards to deck based on x
shuffledDeck = [];
    for i = 1:length(deck)
        b = deck(x(i),:);
        shuffledDeck = [shuffledDeck; b];
    end
end
