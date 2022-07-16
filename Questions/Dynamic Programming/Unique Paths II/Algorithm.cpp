class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        // Swap the 0 + 1s
        for (int ii = 0; ii < obstacleGrid.size(); ii++) {
            for (int jj = 0; jj < obstacleGrid[0].size(); jj++) {
                if (obstacleGrid[ii][jj] == 1)
                    obstacleGrid[ii][jj] = 0;
                else
                    obstacleGrid[ii][jj] = 1;
            }
        }
        
        for (int ii = 0; ii < obstacleGrid.size(); ii++) {
            for (int jj = 0; jj < obstacleGrid[0].size(); jj++) {
                if (obstacleGrid[ii][jj] != 0) {
                    if (ii == 0 && jj == 0)
                        continue;
                    
                    int sum = 0;
                    if (jj-1 >= 0)
                        sum += obstacleGrid[ii][jj-1];
                    if (ii-1 >= 0)
                        sum += obstacleGrid[ii-1][jj];
                    obstacleGrid[ii][jj] = sum;
                }
            }
        }
        
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};