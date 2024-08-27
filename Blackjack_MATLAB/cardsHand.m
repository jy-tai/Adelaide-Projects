% function [hand] = cardsHand(number,profile)
% keep track of number of cards in hand.
[x, y] = size(profiles);
hand = [];
for i = 1:x
   hand = [hand; length(profiles(x,2:end))];
end