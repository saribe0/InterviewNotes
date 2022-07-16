class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        
        vector<int> prevRow;
        vector<int> currentRow;
        
        for(int currRow = 1; currRow <= rowIndex+1; currRow++) {
            
            prevRow = currentRow;
            currentRow = vector<int>();
            
            for(int elem = 0; elem < currRow; elem++) {
                        
                if (elem == 0)
                    currentRow.push_back(1);
                else if (elem == currRow-1)
                    currentRow.push_back(1);
                else
                    currentRow.push_back(prevRow[elem-1] + prevRow[elem]);
            }
        }
        
        return currentRow;
    }
};