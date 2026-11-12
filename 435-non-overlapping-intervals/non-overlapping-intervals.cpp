class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;
        int count = 0;
        while(j < n){
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];
            if(ce <= ns){
                i=j;
                j++;
            }
            else if(ce < ne){
                j++;
                count++;
            }
            else{
                i = j;
                j++;
                count++;
            }
        } return count;
    }
};