class Solution {
    void swapNumsAtIndex(vector<int>& nums, int lhs, int rhs) {
        int tempNum = nums[lhs];
        nums[lhs] = nums[rhs];
        nums[rhs] = tempNum;
    }
public:
    void nextPermutation(vector<int>& nums) {
        
        int pivotIndex = nums.size()-2;
        bool found = false;
        for (; pivotIndex >= 0; pivotIndex--) {
            for(int backIndex = nums.size()-1; backIndex > pivotIndex; backIndex--) {
                if (nums[backIndex] > nums[pivotIndex]) {
                    swapNumsAtIndex(nums, backIndex, pivotIndex);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        
        pivotIndex++;
        
        // 0, 1, 2, [3, 4, 5, 6, 7]
        //             ^
        // 0, 1, 2, [3, 4, 5, 6, 7]
        
        for (int index = 0; index <= (nums.size()-pivotIndex-1)/2; index++) {
            swapNumsAtIndex(nums, index+pivotIndex, nums.size()-index-1);
        }
    }
};