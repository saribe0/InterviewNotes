class Solution {
    
private:
    vector<vector<int>> twoSum(vector<int>&nums, int lhs, int target) {
        vector<vector<int>> res;
        int rhs = nums.size() - 1;
        if (lhs > rhs)
            return res;
        int prevLhs = nums[lhs];
        int prevRhs = nums[rhs];
        bool updatedLhs = false;
        bool updatedRhs = false;
        
        while (lhs < rhs) {
            
            if (updatedLhs && nums[lhs] == prevLhs) {
                lhs++;
                continue;
            }
            prevLhs = nums[lhs];
            if (updatedRhs && nums[rhs] == prevRhs) {
                rhs--;
                continue;
            }
            prevRhs = nums[rhs];
            
            
            int sum = nums[lhs] + nums[rhs];
            if (sum == target) {
                res.push_back({nums[lhs], nums[rhs]});
                lhs++;
                updatedLhs = true;
                updatedRhs = false;
            }
            else if (sum < target) {
                lhs++;
                updatedLhs = true;
                updatedRhs = false;
            }
            else if (sum > target) {
                rhs--;
                updatedLhs = false;
                updatedRhs = true;
            }
        }
        
        return res;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 4)
            return res;
        
        int prevNum = INT_MIN;
        for(int a = 0; a < nums.size() - 3; a++) {
            if (nums[a] == prevNum) {
                continue;
            }
            prevNum = nums[a];
            int prevB = INT_MIN;
            for (int b = a + 1; b < nums.size() - 2; b++ ) {
                if (nums[b] == prevB)
                    continue;
                prevB = nums[b];
                int diffTarget = target - nums[a] - nums[b];
                
                for (auto twoSums: twoSum(nums, b+1, diffTarget)) {
                    twoSums.insert(twoSums.begin(), nums[b]);
                    twoSums.insert(twoSums.begin(), nums[a]);
                    res.push_back(twoSums);
                }
                
            }
        }
        return res;
    }
};        