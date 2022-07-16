class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows (numRows, "");
        
        int row = 0;
        int zigZagUp = 1;
        for (auto charInS: s) {
            rows[row] += charInS;
            
            if (row == 0) {
                zigZagUp = 1;
            }
            if (row == numRows-1) {
                zigZagUp = -1;
            }
            row += 1 * zigZagUp;
            if( row < 0 )
                row = 0;
        }
        
        string combinedRows = "";
        for (auto rowString: rows) {
            combinedRows += rowString;
        }
        
        return combinedRows;
    }
};