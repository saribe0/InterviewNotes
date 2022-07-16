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
    
    int maxDepth(TreeNode* root) {
        if (!root)
             return 0;
        int leftDepth = 1+maxDepth(root->left);
        int rightDepth = 1+maxDepth(root->right);
        
        if (rightDepth>leftDepth)
            return rightDepth;
        else
            return leftDepth;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if (!root) {
            return true;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int depthDifference = leftDepth-rightDepth;
        
        return (depthDifference*depthDifference <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};