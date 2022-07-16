class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> valToIndex;
        for(int index = 0; index < nums.size(); index++) {
            int complement = target - nums[index];
            if (valToIndex.count(complement))
                return {valToIndex[complement], index};
            else
                valToIndex[nums[index]] = index;
        }
        return {0,0};
    }
};