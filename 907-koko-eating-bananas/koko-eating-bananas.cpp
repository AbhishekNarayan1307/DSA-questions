
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l <= r) {
            int mid = l + (r-l)/2;
            long long totaltime = 0;

            for(int j = 0; j < piles.size(); j++) {
                totaltime += (piles[j] + mid - 1) / mid;
            }

            if(totaltime <= h)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};
