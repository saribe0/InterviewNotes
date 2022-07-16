class Solution {
private:
    bool isOpen(char character) {
        switch (character) {
            case '(':
                return true;
            case '{':
                return true;
            case '[':
                return true;
        }
        return false;
    }
    
    char closedBy(char openChar) {
        switch (openChar) {
            case '(':
                return ')';
            case '{':
                return '}';
            case '[':
                return ']';
        }
        return openChar;
    }

public:
    bool isValid(string s) {
        std::stack<char> parentheses;
        for(auto character: s) {
            if (isOpen(character)) {
                parentheses.push(character);
            }
            else {
                if (parentheses.size() == 0) {
                    return false;
                }
                else {
                    char poppedChar = parentheses.top();
                    parentheses.pop();
                    if (character != closedBy(poppedChar)) {
                        return false;
                    }
                }
            }
        }
        return (parentheses.size() == 0);
    }
};