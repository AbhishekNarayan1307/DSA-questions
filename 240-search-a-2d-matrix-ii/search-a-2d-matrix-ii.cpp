class Solution {
public:
    bool bs(vector<vector<int>>& matrix, int target, int i){
        int n = matrix[i].size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(matrix[i][m] == target) return true;
            else if(matrix[i][m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        for(int i = 0; i < matrix.size(); i++){
            if(target >= matrix[i][0] && target <= matrix[i][matrix[i].size()-1]){
                ans = ans || bs(matrix, target, i);
            }
        }
        return ans;
    }
};