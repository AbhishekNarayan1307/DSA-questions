class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool not_ins = 1;
        int i = 0;
        while(i < intervals.size()){
            if(not_ins){
                if(intervals[i][1] < newInterval[0]){
                    ans.push_back(intervals[i]);
                }
                else if(intervals[i][0] > newInterval[1]){
                    ans.push_back(newInterval);
                    not_ins = 0;
                }
                else{
                    newInterval[0] = min(newInterval[0], intervals[i][0]);
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                }
            }
            if(!not_ins){
                ans.push_back(intervals[i]);
            }
            i++;
        }
        if(not_ins) ans.push_back(newInterval);
        return ans;
    }
};