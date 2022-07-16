class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> allRows = {};
        for(int row = 1; row <= numRows; row++) {
            
            vector<int> newRow = {};
            
            for (int rowIndex = 0; rowIndex < row; rowIndex++) {
                if (allRows.size() <= row-2)
                    newRow.push_back(1);
                else if (rowIndex == 0)
                    newRow.push_back(1);
                else if (rowIndex == row-1)
                    newRow.push_back(1);
                else{
                    newRow.push_back(allRows[row-2][rowIndex-1]+allRows[row-2][rowIndex]);  
                }              
            }
            
            allRows.push_back(newRow);            
        }
        return allRows;
    }
};