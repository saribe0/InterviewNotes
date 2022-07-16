class Solution {
private:
    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int workingIndex = 0;
        int leftPartitionEnd = nums.size()-1;
        
        while (workingIndex != leftPartitionEnd) {
            
            if (workingIndex+1 == nums[workingIndex]) {
                workingIndex++;
            }
            else if (nums[workingIndex] < 1 || nums[workingIndex] > leftPartitionEnd || nums[workingIndex] == nums[nums[workingIndex]-1]) {
                swap(nums, workingIndex, leftPartitionEnd);
                leftPartitionEnd--;
            }
            else {
                swap(nums, workingIndex, nums[workingIndex]-1);
            }
        }
        
        for (int index = 0; index<nums.size(); index++) {
            if (nums[index] != index+1)
                return index+1;
        }
        return nums.size()+1;
    }
};
