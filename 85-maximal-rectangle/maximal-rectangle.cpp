class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        stack<int> st;
        //for prev smallest
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] >= height[i]) st.pop();
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //for next smallest
        for(int i = n -1; i>=0; i--){
            while(!st.empty() && height[st.top()] >= height[i]) st.pop();
            right[i] = st.empty()? n : st.top();
            st.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, height[i]*(right[i] - left[i] - 1));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n, vector<int>(m));
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (matrix[i][j] - '0');
                if(matrix[i][j] == '0') sum = 0;
                psum[i][j] = sum;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, largestRectangleArea(psum[i]));
        }
        return ans;
    }
};