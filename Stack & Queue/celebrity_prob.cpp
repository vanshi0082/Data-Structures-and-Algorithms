
class Solution {
  public:
    
    int celebrity(vector<vector<int> >& mat) {
        int ans = -1;
       stack<int> st;
       for(int i=0;i<mat.size();i++){
          st.push(i);
      }
      
        while(st.size()>0){
            if(st.size()==1){
                ans=st.top();
                break;
            }
          int a = st.top();
          st.pop();
          int b = st.top();
          st.pop();
            
            if(mat[a][b]==1&&mat[b][a]==0){
                st.push(b);
            }
            if(mat[b][a]==1&&mat[a][b]==0){
                st.push(a);
            }
        }
        if(st.size()==0){
            return -1;
        }
        
        for(int i=0;i<mat.size();i++){
            if(mat[ans][i]==1){
                return -1;
        }
        if(i!=ans && mat[i][ans]==0){
            return -1;
        }
        }
      
      return ans;
      
      
      
    }
};

//{ Driver Code Starts.

int main()
{
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };
    Solution sol;
    int id = sol.celebrity(matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;
    return 0;
}

// } Driver Code Ends