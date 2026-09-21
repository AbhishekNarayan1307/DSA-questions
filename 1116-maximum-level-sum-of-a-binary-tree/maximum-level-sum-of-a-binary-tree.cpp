class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            for(int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            ans.push_back(level);
        }

        return ans;
    }

    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> ans = levelOrder(root);

        int maxm = INT_MIN;
        int sol = 1;

        for(int i = 0; i < ans.size(); i++) {
            int sum = accumulate(ans[i].begin(),
                                 ans[i].end(), 0);

            if(sum > maxm) {
                maxm = sum;
                sol = i + 1;
            }
        }

        return sol;
    }
};