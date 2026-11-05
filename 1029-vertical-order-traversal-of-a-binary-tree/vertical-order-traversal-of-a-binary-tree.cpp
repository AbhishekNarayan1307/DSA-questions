class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> res;

        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [curr, row, col] = q.front();
            q.pop();

            mp[col][row].insert(curr->val);

            if (curr->left)
                q.push({curr->left, row + 1, col - 1});

            if (curr->right)
                q.push({curr->right, row + 1, col + 1});
        }

        for (auto &col : mp) {
            vector<int> temp;

            for (auto &row : col.second) {
                for (auto &val : row.second) {
                    temp.push_back(val);
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};