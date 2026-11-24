#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> count;
        int a = -1; // repeated
        int b = -1; // missing

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                count[grid[i][j]]++;
                if(count[grid[i][j]] == 2){
                    a = grid[i][j];
                }
            }
        }

        for(int i = 1; i <= n*n; i++){
            if(count.find(i) == count.end()){
                b = i;
                break;
            }
        }

        return {a, b};
    }
};