class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> small = nums1.size()<nums2.size()? nums1:nums2;
        vector<int> large = nums1.size()<nums2.size()? nums2:nums1;

        int m = small.size(), n = large.size();

        int low = 0, high = small.size() ;
        while(low <= high){
            int cut1 = (low + high)/2;
            int cut2 = (m+n+1)/2 - cut1;

            int l1 = cut1==0?INT_MIN: small[cut1-1];
            int l2 = cut2==0?INT_MIN: large[cut2-1];
            int r1 = cut1==m?INT_MAX: small[cut1];
            int r2 = cut2==n?INT_MAX: large[cut2];

            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2 == 0){
                    return ((double)max(l1, l2) + min(r1, r2))/2.0;
                    
                }
                else return max(l1, l2);
            }
            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return -1;
        

    }
};