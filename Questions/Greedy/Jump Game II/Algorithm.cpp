class Solution {
/*

1. Check to see if you can jump to the end, if so, do it, 
2. Determine the jump that gives you the max next distance
3. Take it
4. -> 1

*/
private:
    int jumpsTaken = 0;
    
    void takeJump(vector<int>& nums, int currentIndex) {
        
        // Can we get there without taking a jump?
        if (currentIndex + nums[currentIndex] >= nums.size()-1) {
            jumpsTaken++;
            return;
        }
        
        jumpsTaken++;
        
        // If not, take the one that gets us the farthest
        int maxIndex = currentIndex + 1;
        for (int possibleJumps = 1; possibleJumps <= nums[currentIndex]; possibleJumps++) {
            
            if (nums[currentIndex+possibleJumps] + possibleJumps + currentIndex > nums[maxIndex] + maxIndex) {
                maxIndex = currentIndex + possibleJumps;
            }    
        } 
        
        takeJump(nums, maxIndex);
    }
    
public:
    int jump(vector<int>& nums) {
        
        if (nums.size() == 1)
            return 0;
        
        takeJump(nums, 0);
        return jumpsTaken;
    }
};