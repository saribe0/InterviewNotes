class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int index = 0;
        bool findingPrefix = true;
        do {
            char currentChar;
            if (index < strs[0].size()) {
                currentChar = strs[0][index];
            }
            else {
                findingPrefix = false;
            }
            for (int otherStringsIndex = 1; otherStringsIndex < strs.size(); otherStringsIndex++) {
                if (!(index < strs[otherStringsIndex].size() && strs[otherStringsIndex][index] == currentChar))
                    findingPrefix = false;
            }
            if (findingPrefix) {
                prefix += currentChar;
                index++;
            }
        } while (findingPrefix);
        return prefix;
    }
};