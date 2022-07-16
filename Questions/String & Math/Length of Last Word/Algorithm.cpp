class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int lastWordEnd = 0;
        for (int index=s.size()-1; index>=0; index--) {
            if (s[index] != ' ' && lastWordEnd == 0){
                lastWordEnd = index+1;}
            else if (s[index] == ' ' && lastWordEnd != 0){
                return lastWordEnd-index-1;}
        }
        return lastWordEnd;
    }
};