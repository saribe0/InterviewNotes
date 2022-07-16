class Solution {
public:
    string addBinary(string a, string b) {
        
        string out = "";
        bool carry = false;
        for(int index = 1; index <= a.size() || index<=b.size(); index++) {
            char aVal = '0';
            char bVal = '0';
            if (index <= a.size())
                aVal = a[a.size()-index];
            if (index <= b.size())
                bVal = b[b.size()-index];
            if (aVal == '1' && bVal == '1') {
                if (carry) {
                    out = '1' + out;
                }
                else{
                    out = '0' + out;
                    carry = true;
                }
            }
            else if (aVal == '1' || bVal == '1') {
                if (carry) {
                    out = '0' + out;
                }
                else{
                    out = '1' + out;
                }
            }
            else {
                if (carry) {
                    out = '1' + out;
                    carry = false;
                }
                else{
                    out = '0' + out;
                }
            }
        }
        if (carry)
            out = '1' + out;
        return out;
        
    }
};