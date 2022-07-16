class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> spiral;
        
        int x = 0;
        int y = 0;
        int xMax = matrix[0].size() - 1;
        int yMax = matrix.size() - 1;
        int xMin = 0;
        int yMin = 1;
        int max = (yMax + 1) * (xMax + 1);
        int count = 0;
        int state = 0;
        while (max > count) {
            spiral.push_back(matrix[y][x]);
            count++;
            
            
            if (y == yMin && state == 3) {
                state = 0;
                yMin++;
            }
            if (x == xMax && state == 0) {
                state = 1;
                xMax--;
            }
            if (y == yMax && state == 1) {
                state = 2;
                yMax--;
            }
            if (x == xMin && state == 2) {
                state = 3;
                xMin++;
            }
            
            if (x < xMax && state == 0)
                x++;
            else if (y < yMax && state == 1)
                y++;
            else if (x > xMin && state == 2)
                x--;
            else if (y > yMin && state == 3)
                y--;
                
        }
        return spiral;
    }
};