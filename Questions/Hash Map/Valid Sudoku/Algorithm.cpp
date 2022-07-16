class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> seenColNums(9, vector<int>(9, 0));
        vector<vector<int>> seenSqrNums(9, vector<int>(9, 0));
        
        for (int col = 0; col < 9; col++) {
            
            vector<int> seenRowNums(9, 0);
            for (int row = 0; row < 9; row++) {
                
                
                int val = board[row][col] - '1';
                if (val < 0 || val > 8)
                    continue;
                
                if (row == 3) {
                    cout << board[row][col] <<endl;
                }
                
                // Check the row
                seenRowNums[val]++;
                if (seenRowNums[val] > 1)
                    return false;
                
                // Check the column
                seenColNums[row][val]++;
                if (seenColNums[row][val] > 1)
                    return false;
                
                // Check the square
                int sqrIndex = (row/3)*3 + col/3;
                seenSqrNums[sqrIndex][val]++;
                if (seenSqrNums[sqrIndex][val] > 1)
                    return false;
            }
        }
        return true;
    }
};