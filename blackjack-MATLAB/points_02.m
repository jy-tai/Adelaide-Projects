function [sumScore] = points_02(card)
% calcualte points for each player based on the cards drawn
    sumScore = 0;
    for i = 1:length(card)
        switch card(i)    % calculate points
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

    numA = sum(strcmp("A",card));   % calculate the number of A
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
end