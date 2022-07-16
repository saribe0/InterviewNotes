class Solution {
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_map<int, int> mToZero;
        unordered_map<int, int> nToZero; 
        
        for (int m = 0; m < matrix.size(); m++) {
            for (int n = 0; n < matrix[0].size(); n++) {
                if (matrix[m][n] == 0) {
                    mToZero[m] = 1;
                    nToZero[n] = 1;
                }
            }
        }
        
        for (int m = 0; m < matrix.size(); m++) {
            for (int n = 0; n < matrix[0].size(); n++) {
                if (mToZero.count(m) || nToZero.count(n))
                    matrix[m][n] = 0;
            }
        }
    }
};