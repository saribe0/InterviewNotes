class Solution {
    
    int maxIndex(vector<int>& nums, int target, int lhs, int rhs) {
        
        int midIndex = lhs + (rhs-lhs) / 2;
        if (nums[midIndex] == target && (midIndex == nums.size()-1 || nums[midIndex+1] != target)) {
            return midIndex;
        }
        
        if (rhs - lhs <= 1)
            return -1;
    
        // Split up the vector and keep looking
        if (nums[midIndex] > target)
            return maxIndex(nums, target, lhs, midIndex);
        else
            return maxIndex(nums, target, midIndex, rhs);
    }
    
    int minIndex(vector<int>& nums, int target, int lhs, int rhs) {
        
        int midIndex = lhs + (rhs-lhs) / 2;
        if (nums[midIndex] == target && (midIndex == 0 || nums[midIndex-1] != target)) {
            return midIndex;
        }
        
        if (rhs - lhs <= 1)
            return -1;
        
        // Split up the vector and keep looking
        if (nums[midIndex] >= target)
            return minIndex(nums, target, lhs, midIndex);
        else
            return minIndex(nums, target, midIndex, rhs);
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> defaultRes({-1,-1});

        if (nums.size() == 0)
            return defaultRes;
        if (nums.size() == 1)
            if (nums[0] == target)
                return {0, 0};
            else
                return defaultRes;
        
        int min, max;
        min = minIndex(nums, target, 0, nums.size());
        max = maxIndex(nums, target, 0, nums.size());
        
        return vector<int>({min, max});
    }
};