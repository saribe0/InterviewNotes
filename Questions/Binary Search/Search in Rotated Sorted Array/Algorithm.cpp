class Solution {
    
    /*
    [4,5,6,7,0,1,2]
    
    [4, 5, 6] [7, 0, 1, 2]
    
    [4, 5] [6] [7, 0] [1, 2]
    
    
    */
    
private:
    int search(vector<int>& nums, int target, int lhs, int rhs) {
        
        if (target == nums[lhs])
            return lhs;
        else if (target == nums[rhs])
            return rhs;
        else if (rhs - lhs <= 1)
            return -1;
        
        int midIndex = lhs + (rhs-lhs) / 2;
        int mid = nums[midIndex];
        
        if (target == mid)
            return midIndex;
        
        // Case: LHS has the pivot point
        if (nums[lhs] > mid) {
            if (nums[lhs] < target || target < mid) {
                return search(nums, target, lhs, midIndex);
            }
            else {
                return search(nums, target, midIndex, rhs);
            }
        }
        // Case: Has the pivot point
        else {
            if (nums[lhs] < target && target < mid) {
                return search(nums, target, lhs, midIndex);
            }
            else {
                return search(nums, target, midIndex, rhs);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        
        return search(nums, target, 0, nums.size()-1);
    }
};