class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        for (int ii = 0; ii < grid.size(); ii++) {
            for (int jj = 0; jj < grid[0].size(); jj++) {
                
                if (ii > 0 && jj > 0)
                    if (grid[ii-1][jj] > grid[ii][jj-1])
                        grid[ii][jj] += grid[ii][jj-1];
                    else
                        grid[ii][jj] += grid[ii-1][jj];
                else
                    if (ii > 0)
                        grid[ii][jj] += grid[ii-1][jj];
                    else if (jj > 0)
                        grid[ii][jj] += grid[ii][jj-1];
            }   
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
