class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack <int> st;
        for(int a : asteroids){
            if(a > 0) st.push(a);
            else{
                while(!st.empty() && st.top() < -a && st.top() > 0) st.pop();
                if(st.empty() || st.top() < 0) st.push(a);
                else if(!st.empty() && st.top() == -a) st.pop();
            }
        }
        if(st.empty()) return {};
        vector<int> res(st.size());
        int i = res.size() - 1;
        while(!st.empty()){
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
};