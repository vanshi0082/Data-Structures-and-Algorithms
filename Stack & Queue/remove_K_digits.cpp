class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans="";
        int n=num.size();
        for(int i=0;i<n;i++){
            //convert string char to interger for the oprations
            int val = num[i]-'0';
            while(!st.empty()&&k>0&&st.top()>val){
                k--;
                st.pop();
            }
            st.push(val);
        }
        while(k){
            st.pop();
            k--;
        }
        while(st.size()>0){
            ans+=st.top()+'0';
            st.pop();
        }
        while(ans.size()>0&&ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans.size()>0?ans:"0";
       

    }
};
