class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int index = digits.size()-1; index >= 0; index-- ) {
            digits[index]++;
            if (digits[index] == 10) {
                digits[index] = 0;
            }
            else
                break;
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};