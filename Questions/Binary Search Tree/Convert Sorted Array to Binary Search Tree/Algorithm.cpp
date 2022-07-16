/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int min, int max) {
        
        if (max - min == 0)
            return nullptr;
        
        // Create a node for the middle of the vectors
        int midIndex = min + (max - min) / 2;
        TreeNode* sectionRoot = new TreeNode(nums[midIndex]);
        
        // Build up the left and right tree's recursively
        sectionRoot->left = sortedArrayToBST(nums, min, midIndex);
        sectionRoot->right = sortedArrayToBST(nums, midIndex+1, max);
        
        return sectionRoot;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return sortedArrayToBST(nums, 0, nums.size());
    }
};