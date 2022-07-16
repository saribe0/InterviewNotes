class Solution {
    
    bool takeJump(vector<int>& nums, int fromIndex) {
        
        if (fromIndex >= nums.size()-1 || fromIndex+nums[fromIndex] >= nums.size()-1)
            return true;
        if (nums[fromIndex] == 0)
            return false;
        
        // Greedily find the farthest we can get
        int maxIndex = 0;
        for (int toIndex = fromIndex+1; toIndex <= fromIndex + nums[fromIndex]; toIndex++) {
            if (nums[toIndex] + toIndex >= maxIndex + nums[maxIndex])
                maxIndex = toIndex;
        }
        
        //cout<< maxIndex<<endl;
        
        return takeJump(nums, maxIndex);
        
    }
public:
    bool canJump(vector<int>& nums) {
        
        return takeJump(nums, 0);
    }
};
