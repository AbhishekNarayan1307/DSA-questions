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
    int diameter = 0;
    int helper(TreeNode* root){
        if(!root) return 0;
        int LH = helper(root->left);
        int RH = helper(root->right);
        diameter = max(diameter, LH + RH);
        return 1 + max(LH, RH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
    }
};