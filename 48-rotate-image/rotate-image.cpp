class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = matrix[0].size()-1; j>= 0; j--){
                temp[i].push_back(matrix[j][i]);
            }
        }
        matrix = temp;
        return;
    }
};