class Solution {
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        
        unordered_map<int, int> objects;
        
        int rightPtr = nums.size()-1;
        int leftPtr = 0;
        int index = 0;
        
        while (rightPtr > leftPtr && index <= rightPtr) {
            
            if (index < nums.size() && nums[index] == 2) {
                if (index == rightPtr)
                    index++;
                else {
                    swap(nums, index, rightPtr);
                    rightPtr--;
                }
            }
            if (index < nums.size() && nums[index] == 0 ) {
                if (index == leftPtr)
                    index++;
                else {
                    swap(nums, index, leftPtr);
                    leftPtr++;
                }
            }
            if (index < nums.size() && nums[index] == 1) {
                index++;
            }
        }
    }
};