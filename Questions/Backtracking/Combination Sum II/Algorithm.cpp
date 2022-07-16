class Solution {
    
private:
    vector<vector<int>> combinations;
    vector<int> possibleCombo;
    unordered_map<int, int> pickedIndex;
    
    void pickNextNum(vector<int>& candidates, int target, int startingIndex) {
        
        if (target <= 0) {
            if (target == 0) {
                combinations.push_back(possibleCombo);
            }
            return;
        }
        
        for (int pickIndex = startingIndex; pickIndex<candidates.size(); pickIndex++) {
            
            int pick = candidates[pickIndex];
            if (pickedIndex.count(pickIndex) && pickedIndex[pickIndex] > 0)
                continue;
            
            possibleCombo.push_back(pick);
            pickedIndex[pickIndex] = 1;
                
            pickNextNum(candidates, target-pick, pickIndex);
            
            possibleCombo.pop_back();
            pickedIndex[pickIndex] = 0;
            
            while (pickIndex+1 < candidates.size() && candidates[pickIndex] == candidates[pickIndex+1] )
                pickIndex++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        pickNextNum(candidates, target, 0);
        return combinations;
    }
};