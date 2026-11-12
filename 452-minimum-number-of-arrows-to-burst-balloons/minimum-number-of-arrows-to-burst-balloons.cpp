class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

        sort(points.begin(), points.end());

        int res = 1;
        int n = points.size();
        int i = 0, j = 1;

        while(j < n) {
            if(points[i][1] < points[j][0]) {
                i = j;
                res++;
            }
            else {
                points[i][1] = min(points[i][1], points[j][1]);
            }
            j++;
        }

        return res;
    }
};