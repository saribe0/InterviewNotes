class Solution {
/*
1,1 -> 1,1 1,3
1,2 -> 2,1 2,3
2,1 -> 1,2 1,2
1,3 -> 3,1 3,1
2,3 -> 3,2 3,2
3,2 -> 2,3 2,1
3,3 -> 3,3 3,1
3,1 -> 3,1 1,3


0, 1, 2, 3

top nums:
x = y
y = rows - x

right nums:
x = y
y = rows - x

bottom nums:
x = y
y = rows - x


if (x - cols):
    x + cols;

*/

public:
    void rotate(vector<vector<int>>& matrix) {
        
        
        for(int row = 0; row < matrix.size()/2; row++) {            
            for(int col = row; col < matrix.size()-row-1; col++) {
                
                int currX = col;
                int currY = row;
                int floatingNum = matrix[currX][currY];
                for(int i = 0; i<4; i++) {
                    int nextX = currY;
                    int nextY = matrix.size() - currX -1;
                    
                    int temp = matrix[nextX][nextY];
                    matrix[nextX][nextY] = floatingNum;
                    floatingNum = temp;
                    
                    currX = nextX;
                    currY = nextY;
                    
                }
            }
        }
    }
};