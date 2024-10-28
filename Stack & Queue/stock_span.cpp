#include<bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int> arr){
    stack<int> st;
    vector<int> ans(arr.size());
    ans[0]=1;
    st.push(0);

    for(int i=1;i<arr.size();i++){
        while(!st.empty()&&arr[st.top()]<=arr[i]){
            st.pop();
        }

        ans[i]= st.empty()?(i+1):(i-st.top());
        st.push(i);
    }
    return ans;
}
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

int main()
{
    vector<int> price = { 10, 4, 5, 90, 120, 80 };
  
    vector<int> ans = calculateSpan(price);

   
    printArray(ans);

    return 0;
}