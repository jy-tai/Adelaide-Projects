function [sumScore] = points_final(card)
% calcualte and return the points for each player base on cards drawn
    sumScore = 0;
    for i = 1:length(card)
        switch card(i)    % calculate points
            case {"2","3","4","5","6","7","8","9","10"}
                sumScore = sumScore + str2num(card(i));
            case {"J","Q","K"}
                sumScore = sumScore + 10;
        end
    end
    
    % calculate the number of As by
    % use of sum and strcmp to add up the values of the logical array
    numA = sum(strcmp("A",card));
    
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