#include<bits/stdc++.h>
using namespace std;

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

int histo(vector<int> r){
    int n = r.size();
        vector<int> nse = nextS(r);
        vector<int> pse = prevS(r);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, (r[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
}

int passRow(vector<vector<int>> &mat, int n, int m){
    vector<int> r(m,0);
    inr maxArea = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                r[j]++;
            }
            else{
                r[j]=0;
            }
       }
       int area = histo(r);
       maxAns = max(area,maxAns);
    }
}

int main() {

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}
    };
    int n = 4, m = 5;
    int maxArea = passRow(mat, n, m);
    cout << "The maximum are is: " << maxArea << "\n";
    return 0;
}