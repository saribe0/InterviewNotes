class Solution {
public:
    int myAtoi(string s) {
        
        bool isPositive = true;
        bool parsingInt = false;
        
        vector<int> numDigits;
        
        // Get the characters and signage
        for (auto currentChar: s) {
            
            // All the starting values
            if (currentChar == ' ' && !parsingInt)
                continue;
            if (currentChar == '-' && !parsingInt) {
                isPositive = false;
                parsingInt = true;
                continue;
            }
            else if (currentChar == '+' && !parsingInt) {
                isPositive = true;
                parsingInt = true;
                continue;
            }
                
            if (currentChar >= '0' && currentChar <= '9'){
                parsingInt = true;
                numDigits.push_back(currentChar - '0');
            }
            else if (!parsingInt) {
                return 0;
            }
            else if (parsingInt)
                break;
        }
        
        // Convert to a valid number
        int sInt = 0;
        for (auto digit: numDigits) {
            
            if (sInt > 0 && !isPositive) {
                sInt *= -1;
            }
            
            if (isPositive && (INT_MAX / 10 < sInt || INT_MAX - digit < sInt*10)) {
                return INT_MAX;
            } 
            if (!isPositive && (INT_MIN / 10 > sInt || INT_MIN - sInt*10 > digit*-1)) {
                return INT_MIN;
            }
            
            if (isPositive) {
                sInt = sInt * 10 + digit;
            }
            else {
                sInt = sInt * 10 - digit;
            }
        }

        return sInt;
    }
};