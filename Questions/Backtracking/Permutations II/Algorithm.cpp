class Solution {
    
private:
    vector<vector<int>> permutations;
    //vector<int> currentPermutation;
    vector<int> seenIndex;
    
    void permute(vector<int>& nums, vector<int>& currentPermutation) {
        
        if (nums.size() == currentPermutation.size()) {
            permutations.push_back(currentPermutation);
            return;
        }
        
        int prevPick = -11;
        for (int index = 0; index < nums.size(); index++) {
            
            if (seenIndex[index] == 1)
                continue;
            
            if (prevPick == nums[index])
                continue;

            prevPick = nums[index];
            seenIndex[index] = 1;
            currentPermutation.push_back(nums[index]);
            
            permute(nums, currentPermutation);
            
            seenIndex[index] = 0;
            currentPermutation.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        seenIndex = vector<int>(8, 0);
        vector<int> currentPermutation;
        permute(nums, currentPermutation);
        return permutations;
    }
};