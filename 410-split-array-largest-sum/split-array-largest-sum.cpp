
class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid) {
        int count = 1, sum = 0;

        for(int x : nums) {
            if(sum + x > mid) {
                count++;
                sum = x;
            }
            else {
                sum += x;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(possible(nums, k, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};
