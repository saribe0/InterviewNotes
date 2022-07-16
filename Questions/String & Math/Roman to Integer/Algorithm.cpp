class Solution {
public:
    int romanToInt(string s) {
        int totalValue = 0;
        int previousValue = 0;
        for (std::string::iterator it = s.begin(); it!=s.end(); ++it ){
            int currentValue = romanCharToString(*it);
            if (previousValue < currentValue) {
                totalValue-=previousValue;
            }
            else {
                totalValue+=previousValue;
            }
            previousValue = currentValue;
        }
        totalValue += previousValue;
        return totalValue;
    }

private:
    int romanCharToString(char character) {
        switch (character) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
};