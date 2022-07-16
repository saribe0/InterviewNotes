class Solution {
public:
    vector<string> letterCombinations(string digits) {
  
        unordered_map<char, string> numToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
            
        vector<string> letterCombos;
            
        for (auto digit: digits) {
            vector<string> updatedCombos;
            for (auto possibleChar: numToLetters[digit]) {
                if (letterCombos.empty()) {
                    string charAsString;
                    charAsString.push_back(possibleChar);
                    updatedCombos.push_back(charAsString);
                }
                for (auto existingCombo: letterCombos) {
                    updatedCombos.push_back(existingCombo + possibleChar);
                }
            }
            letterCombos = updatedCombos;
        }
        
        return letterCombos;
    }
};