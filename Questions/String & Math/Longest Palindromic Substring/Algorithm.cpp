class Solution {

private:
    string getLargestPalindroneAtIndex(string s, int startingIndex) {

        int lhs = startingIndex;
        int rhs = startingIndex;
        // babad 
        //   b    2,2 -> 1,3
        //  aba   1,3 -> 0,4
        // babad  0,4 XXX
        while(lhs >= 0 && rhs < s.size() && s[lhs] == s[rhs]) {
            lhs--;
            rhs++;
        }
        
        int lhs2 = startingIndex;
        int rhs2 = startingIndex+1;
        // babad 
        //   b    2,2 -> 1,3
        //  aba   1,3 -> 0,4
        // babad  0,4 XXX
        while(lhs2 >= 0 && rhs2 < s.size() && s[lhs2] == s[rhs2]) {
            lhs2--;
            rhs2++;
        }
        
        if (rhs-lhs < rhs2 - lhs2)
            return s.substr(lhs2+1, rhs2-lhs2-1);
        else
            return s.substr(lhs+1, rhs-lhs-1);
    }

public:
    string longestPalindrome(string s) {
        string longestPalindrome = s.substr(0, 1);
        for (int index = 0; index < s.size(); index++) {
            string largestPalindromeAtIndex = getLargestPalindroneAtIndex(s, index);
            if (longestPalindrome.size() < largestPalindromeAtIndex.size()) {
                longestPalindrome = largestPalindromeAtIndex;
            }
        }
        return longestPalindrome;
    }
};