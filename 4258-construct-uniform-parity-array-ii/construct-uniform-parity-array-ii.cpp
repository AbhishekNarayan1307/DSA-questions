class Solution {
public:
    bool uniformArray(vector<int>& n) {
        sort(n.begin(), n.end());
        int x = n[0]%2;
        int po = 0;
        int pe = 0;
        for(int i = 1; i < n.size(); i++){
           if(x != n[i]%2){
            if((n[i] - n[0])%2==0) pe++;
            else po++;
           }
           else{
            if(x == 0) pe++;
            else po++;
           }
        }
        if((x == 1 && po == n.size() - 1) || (x == 0 && pe == n.size() - 1 )) return true;
        return false;
    }
};