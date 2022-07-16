class Solution {
    int index = 0;
    string decodeStringAt(string s) {
        
        string substr = "";
        
        int k = 0;
        bool searching_for_substring = false;
        
        while(index < s.size()) {
            char character = s[index];
            cout << character <<endl;
            cout << substr <<endl;
            index++;

            if (character >= '0' && character <= '9') {
                // integer so push back
                k = (10 * k + (character - '0'));
            }
            else if (character == '[') {
                searching_for_substring = true;
                string decodeSubstring = decodeStringAt(s);
                for (int ii = 0; ii < k; ii++) {
                    substr += decodeSubstring;
                }
                k = 0;
                searching_for_substring = false;
            }
            else if (character == ']') {
                if (!searching_for_substring) {
                    return substr;
                }
            }
            else if (!searching_for_substring) {
                // Normal character
                substr += character;
            }
        }
        return substr;
    }
public:
    string decodeString(string s) {
       return decodeStringAt(s);
    }
};