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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val==q->val) && (isSame(p->left, q->left)) && isSame(p->right, q->right);
    }
    bool helper(TreeNode* p, TreeNode* q){
        if(!p) return false;
        if(isSame(p, q)) return true;
        return (helper(p->left, q) ||  helper(p->right, q));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        return helper(root, subRoot);
        
    }
};