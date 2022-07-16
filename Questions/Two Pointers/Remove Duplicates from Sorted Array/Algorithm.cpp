class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int nonDuplicateIndex = 1;
        int previousNum = nums[0];
        for(int index = 1; index < nums.size(); index++) {
            if (nums[index] != previousNum) {
                nums[nonDuplicateIndex] = nums[index];
                nonDuplicateIndex++;
            }
            previousNum = nums[index];
        }
        
        return nonDuplicateIndex;
    }
};