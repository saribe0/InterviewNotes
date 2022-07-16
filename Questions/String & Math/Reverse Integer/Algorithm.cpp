class Solution {
private:
    vector<int> getDigitsOfX(int x) {
        
        int negativeFlag = 1;
        if (x < 0)
            negativeFlag = -1;
        
        // Push digits of x into an array, thus reversing the digits
        // x = 123
        // 3, 2, 1
        vector<int> digitsOfX;
        do {
            digitsOfX.push_back(x % 10 *negativeFlag);
            x /= 10;
        } while (x != 0);
        
        return digitsOfX;
    }
    
    bool outsideRange(vector<int> val, vector<int> compare) {
        
        if (compare.size() > val.size())
            return false;
        for (int index = 0; index < compare.size(); index++) {
            if (compare[compare.size() - 1 - index] < val[index])
                return true;
            else if (compare[compare.size() - 1 - index] > val[index])
                return false;
        }
        return false;
    }
public:
    int reverse(int x) {
        
        // First store whether x is negative or not so we can work only with positive numbers
        int isNegative = 1;
        if (x < 0) {
            isNegative = -1;
        }
        
        vector<int> digitsMax = getDigitsOfX(INT_MAX);
        vector<int> digitsMin = getDigitsOfX(INT_MIN);
        vector<int> digitsOfX = getDigitsOfX(x);
        
        if (isNegative == 1)
            if (outsideRange(digitsOfX, digitsMax))
                return 0;
        if (isNegative == -1)
            if (outsideRange(digitsOfX, digitsMin))
                return 0;
        
        // Build back up the return value
        int returnVal = 0;
        int multiplier = 1;
        for (int ii = digitsOfX.size()-1; ii >=0; ii--) {
            returnVal += digitsOfX[ii] * multiplier;
            if (ii != 0)
                multiplier *= 10;
        }
        
        return returnVal * isNegative;
        
    }
};