class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (mid > 0 && nums[mid] == nums[mid - 1]) {

                if ((mid - s) % 2 == 0) {
                    e = mid - 2;
                } else {
                    s = mid + 1;
                }

            } else if (mid < nums.size() - 1 &&
                       nums[mid] == nums[mid + 1]) {

                if ((mid - s) % 2 == 0) {
                    s = mid + 2;
                } else {
                    e = mid - 1;
                }

            } else {
                return nums[mid];
            }
        }

        return -1;
    }
};