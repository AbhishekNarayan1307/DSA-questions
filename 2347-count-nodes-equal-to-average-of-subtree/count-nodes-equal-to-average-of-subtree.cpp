class Solution {
public:
    pair<int, int> solve(TreeNode* root, int &ans) {
        if (root == nullptr)
            return {0, 0};

        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        int average = sum / count;

        if (root->val == average)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};