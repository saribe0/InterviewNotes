class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // Create the results vector
        vector<vector<int>> res(n, vector<int>(n, 0));
                
        int count = 1;
        int x = -1;
        int y = 0;
        int xMax = n;
        int yMax = n;
        int xMin = 0;
        int yMin = 1;
        while (count <= n*n) {
            
            // Do one rotation
            while (x < xMax-1 && count <= n*n) {
                x++;
                res[y][x] = count;
                count++;
            }
            while (y < yMax-1 && count <= n*n) {
                y++;
                res[y][x] = count;
                count++;
            }
            while (x >= xMin+1 && count <= n*n) {
                x--;
                res[y][x] = count;
                count++;
            }
            while (y >= yMin+1 && count <= n*n) {
                y--;
                res[y][x] = count;
                count++;
            }
            
            // Update bounds
            xMax--;
            yMax--;
            xMin++;
            yMin++;
        }
        
        return res;
    }
};