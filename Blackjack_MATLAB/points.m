function [score] = points(numPlayers, profile)
% calcualte points for each player

    score = zeros(numPlayers,2);   % initialise points
    for n = 1:numPlayers
        cards = profile{n,2};
        score(n,1) = n;
        sumScore = 0;
        
        for i = 1:length(cards)
            switch cards(i)    % calculate points
                case "2"
                    sumScore = sumScore + 2;
                case "3"
                    sumScore = sumScore + 3;
                case "4"
                    sumScore = sumScore + 4;
                case "5"
                    sumScore = sumScore + 5;
                case "6"
                    sumScore = sumScore + 6;
                case "7"
                    sumScore = sumScore + 7;
                case "8"
                    sumScore = sumScore + 8;
                case "9"
                    sumScore = sumScore + 9;
                case {"10","J","Q","K"}
                    sumScore = sumScore + 10;
            end
        end

        numA = sum(strcmp("A",profile{n,2}));   % calculate the number of A
        % one A
        if (numA == 1)
            if (sumScore <= 10)
                sumScore = sumScore + 11;
            else
                sumScore = sumScore + 1;
            end
        end
        % two As
        if (numA == 2)
            if (sumScore <= 9)
                sumScore = sumScore + 12;
            else
                sumScore = sumScore + 2;
            end
        end
        % three As
        if (numA == 3)
            if (sumScore <= 8)
                sumScore = sumScore + 13;
            else
                sumScore = sumScore + 3;
            end
        end
        % four As
        if (numA == 4)
            if (sumScore <= 7)
                sumScore = sumScore + 14;
            else
                sumScore = sumScore + 4;
            end
        end
        score(n,2) = sumScore;


    %                 if (sum <= 10)
    %                     valA = 11;  % values of A
    %                 else valA = 1;
    %                 end
    %                 sum(n) = sum(n) + valA;
    end
end