class Solution {
public:
    vector<int> nextS(vector<int> heights){
        int n=heights.size();
        vector<int> nse(n,-1);
        stack<int> st;
        
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
      vector<int> prevS(vector<int> heights){
        int n=heights.size();
        vector<int> ans(n,-1);
        stack<int> st;
      
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = nextS(heights);
        vector<int> pse = prevS(heights);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, (heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
};
