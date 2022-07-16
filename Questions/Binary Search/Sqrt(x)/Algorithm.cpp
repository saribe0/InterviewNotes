class Solution {
public:
    int mySqrt(int x) {
        if (x==0) {
            return 0;
        }
        int high = x;
        int low = 1;
        long long ans;

        while (high >= low) {
            ans = (high - low)/2 + low;
            if (ans*ans > x) {
                ans--;
                high = ans;
            }
            else {
                low = ans+1;
            }
        }
        return ans;
    }
};