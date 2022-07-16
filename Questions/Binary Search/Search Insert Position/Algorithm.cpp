class Solution {
    
private:
    int searchSubsection(vector<int>& nums, int lhIndex, int rhIndex, int target) {
        // Handle some corner cases
        if (target <= nums[lhIndex])
            return lhIndex;
        if (target == nums[rhIndex])
            return rhIndex;
        if (target > nums[rhIndex])
            return rhIndex+1;
        if (rhIndex - lhIndex == 1)
            return rhIndex;
        
        int midIndex = lhIndex + (rhIndex - lhIndex) / 2;
        if (target > nums[midIndex])
            return searchSubsection(nums, midIndex, rhIndex, target);
        else
            return searchSubsection(nums, lhIndex, midIndex, target);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        
        return searchSubsection(nums, 0, nums.size()-1, target);
    }
};