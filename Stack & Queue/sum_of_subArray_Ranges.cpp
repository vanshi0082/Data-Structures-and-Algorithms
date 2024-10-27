class Solution {
public:
 vector<int> pse(vector<int>& arr){
        stack<int> st;
        vector<int> ans1(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans1[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans1;
    }
     vector<int> pge(vector<int>& arr){
        stack<int> st;
        vector<int> ans1(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans1[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans1;
    }

     vector<int> nse(vector<int>& arr){
        stack<int> st;
        vector<int> ans2(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            ans2[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans2;
    }
     vector<int> nge(vector<int>& arr){
        stack<int> st;
        vector<int> ans2(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                st.pop();
            }
            ans2[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans2;
    }


    
    long long subArrayRanges(vector<int>& nums) {
        vector<int> leftMin = pse(nums);
        vector<int> rightMin = nse(nums);
         vector<int> leftMax = pge(nums);
        vector<int> rightMax = nge(nums);
        int mod = 1e9 + 7; // Correct modulo for large integers
        long long ans1 = 0;
        long long ans2 = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            long long countLeft = i - leftMin[i];
            long long countRight = rightMin[i] - i;
            long long contribution = ((countLeft * countRight)  * nums[i]) ;
            ans1 = (ans1 + contribution) ;
        }
         for (int i = 0; i < nums.size(); i++) {
            long long countLeft = i - leftMax[i];
            long long countRight = rightMax[i] - i;
            long long contribution = ((countLeft * countRight)  * nums[i]);
            ans2 = (ans2 + contribution) ;
        }
        long long ans = (ans2-ans1);
        return (long long)ans;
    }
};