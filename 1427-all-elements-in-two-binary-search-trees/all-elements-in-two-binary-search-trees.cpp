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
    void inorder(TreeNode* root, vector<int> &r){
        if(root == NULL) return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1; 
        inorder(root1, r1);
        vector<int> r2;
        inorder(root2, r2);
        vector<int> ans;
        int l = 0, r = 0;
        while(l!= r1.size() && r!=r2.size()){
            if(r1[l] <= r2[r]){
                ans.push_back(r1[l]);
                l++;
            }
            else{
                ans.push_back(r2[r]);
                r++;
            }
        }
        if(l != r1.size()){
            while(l != r1.size()){
                ans.push_back(r1[l]);
                l++;
            }
        }
        if(r != r2.size()){
            while(r != r2.size()){
                ans.push_back(r2[r]);
                r++;
            }
        }
        return ans;
    }
};