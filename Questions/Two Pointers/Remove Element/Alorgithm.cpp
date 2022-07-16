class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int currentIndex = 0;
        for(int index=0; index<nums.size(); index++) {
            if (nums[index] != val) {
                if (currentIndex != index)
                    nums[currentIndex] = nums[index];
                currentIndex++;
            }
        }
        return currentIndex;
    }
};