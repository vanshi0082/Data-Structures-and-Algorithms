class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while (!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top()) {
                    st.pop(); // Destroy the top asteroid
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop(); // Both asteroids destroy each other
                }
                else if (st.empty() || st.top() < 0) {
                    // No collision; add the current asteroid to the stack
                    st.push(asteroids[i]);
                }
            }
        }
        while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};