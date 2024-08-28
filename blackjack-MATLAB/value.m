function [values] = value()
% the points that each card is worth
n=[];
A1 = score(n) + 1;
A11 = score(n) + 11;
two = score(n) + 2;
three = score(n) + 3;
four = score(n) + 4;
five = score(n) + 5;
six = score(n) + 6;
seven = score(n) + 7;
eight = score(n) + 8;
nine = score(n) + 9;
ten = score(n) + 10;
J = score(n) + 10;
Q = score(n) + 10;
K = score(n) + 10;

values = [  A1, A11, two, three, four, five, six, seven, eight, nine, ten,
            J, Q, K  ];
end