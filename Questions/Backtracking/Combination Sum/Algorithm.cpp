class Solution {

// Algorithm
// - Pick one digit, subtract from target
// - Pick another digit, subtract from target
// - If target == 0, add list to the array of digits
// - If target < 0, move on to the next digit
    
private:
    vector<vector<int>> foundSums;
    vector<int> possibleSum;
    
    void pickNum(vector<int>& candidates, int target) {
        
        for (int pick: candidates) {
            
            // Number must be less than the target to be picked
            if (target - pick < 0) {
                continue;
            }
            
            // To enforce no duplicate picks, force sorted
            if (possibleSum.size() > 0 && pick < possibleSum[possibleSum.size()-1]) {
                continue;
            }
            
            // Pick the number
            possibleSum.push_back(pick);
            
            if (target - pick == 0) {
                foundSums.push_back(possibleSum);
                possibleSum.pop_back();
            }
            else {
                pickNum(candidates, target-pick);
                possibleSum.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        pickNum(candidates, target);
        return foundSums;
    }
};