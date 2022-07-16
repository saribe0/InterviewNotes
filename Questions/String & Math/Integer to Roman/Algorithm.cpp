class Solution {
public:
    string intToRoman(int num) {
        
        string roman = "";
            
        unordered_map<int, string> romanMap{
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        
        vector<int> divs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        int divIndex = 0;
        while (num > 0) {
            if (num - divs[divIndex] >= 0) {
                roman += romanMap[divs[divIndex]];
                num -= divs[divIndex];
            }
            else {
                divIndex++;
            }
        }
        
        return roman;
    }
};