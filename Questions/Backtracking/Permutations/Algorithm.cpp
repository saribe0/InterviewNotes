class Solution {
    
private:
    vector<vector<int>> permutations;
    vector<int> currentPermutation;
    vector<int> seenNums;
    
    void pickNum(vector<int>& nums) {
        
        // Backtrack if full
        if (currentPermutation.size() == nums.size()) {
            permutations.push_back(currentPermutation);
            return;
        }
        
        for (int index = 0; index<nums.size(); index++) {
            
            if (seenNums[index] == 1)
                continue;
            
            seenNums[index] = 1;
            currentPermutation.push_back(nums[index]);
            
            pickNum(nums);
            
            seenNums[index] = 0;
            currentPermutation.pop_back();
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        seenNums = vector<int>(6, 0);
        pickNum(nums);
        return permutations;
    }
};