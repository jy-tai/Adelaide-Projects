% deck of cards(52) and perform shuffle
cards = [   "A" "clubs"
            "A" "diamonds"
            "A" "hearts"
            "A" "spades"
            "2" "clubs"
            "2" "diamonds"
            "2" "hearts"
            "2" "spades"
            "3" "clubs"
            "3" "diamonds"
            "3" "hearts"
            "3" "spades"
            "4" "clubs"
            "4" "diamonds"
            "4" "hearts"
            "4" "spades"
            "5" "clubs"
            "5" "diamonds"
            "5" "hearts"
            "5" "spades"
            "6" "clubs"
            "6" "diamonds"
            "6" "hearts"
            "6" "spades"
            "7" "clubs"
            "7" "diamonds"
            "7" "hearts"
            "7" "spades"
            "8" "clubs"
            "8" "diamonds"
            "8" "hearts"
            "8" "spades"
            "9" "clubs"
            "9" "diamonds"
            "9" "hearts"
            "9" "spades"
            "10" "clubs"
            "10" "diamonds"
            "10" "hearts"
            "10" "spades"
            "J" "clubs"
            "J" "diamonds"
            "J" "hearts"
            "J" "spades"
            "Q" "clubs"
            "Q" "diamonds"
            "Q" "hearts"
            "Q" "spades"
            "K" "clubs"
            "K" "diamonds"
            "K" "hearts"
            "K" "spades"    ];

A = cards(1:4,:);
two = cards(5:8,:);
three = cards(9:12,:);
four = cards(13:16,:);
five = cards(17:20,:);
six = cards(21:24,:);
seven = cards(25:28,:);
eight = cards(29:32,:);
nine = cards(33:36,:);
ten = cards(37:40,:);
J = cards(41:44,:);
Q = cards(45:48,:);
K = cards(49:52,:);

x = [];
for i = 1:length(cards)-1
    x(i) = randi([1,52],1);
    x = [x; x(i)];
    
    for j = 1:i-1
    while x(i)==x(j)
        x(i) = randi([1,52],1);
    end
    end
end

shuffledDeck = [];
for i = 1:length(cards)
    b = cards(x(i),:);
    shuffledDeck = [shuffledDeck; b];
end

