class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1) {
            return "1";
        }
        
        string prevSay = countAndSay(n-1);
        string say = "";
        
        char prevDigit = prevSay[0];
        int count = 0;
        for (char digit: prevSay) {
            if (digit == prevDigit) {
                count++;
            }
            else {
                say += count + '0';
                say += prevDigit;
                count = 1;
                prevDigit = digit;
            }
        }
        say += count + '0';
        say += prevDigit;
        
        return say; 
    }
};