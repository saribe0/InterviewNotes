class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        // Keep track of characters seen and their indices
        unordered_map<char, int> indexOfLastOccurenceOf;
        
        // Move through each character, keeping track of the
        // max substring size
        
        int maxUniqueSubstring = 0;
        int startingCharIndex = 0;
        for (int index = 0; index < s.size(); index++) {
            
            // If we've seen this character before, bump the starting index
            // to the one right after it and update maxUniqueSubstring if needed
            if (indexOfLastOccurenceOf.count(s[index]) && indexOfLastOccurenceOf[s[index]] >= 0) {
                if (index-startingCharIndex > maxUniqueSubstring)
                    maxUniqueSubstring = index-startingCharIndex;
                
                
                // Clear out anything from before the new starting index
                int nextStartingIndex = indexOfLastOccurenceOf[s[index]] + 1;
                for (int clearIndex = startingCharIndex; clearIndex < nextStartingIndex; clearIndex++) {
                    indexOfLastOccurenceOf[s[clearIndex]] = -1;
                }
                startingCharIndex = nextStartingIndex;
                
            }
            // Always update the map of seen characters
            indexOfLastOccurenceOf[s[index]] = index;
        }
        
        // Handle the end of the string
        if (s.size() - startingCharIndex > maxUniqueSubstring)
            maxUniqueSubstring = s.size()-startingCharIndex;
                
        return maxUniqueSubstring;
    }
};
