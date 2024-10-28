#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> arr,int k){
    dequeue<int> dq;
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        if(!dq.size()&&dq.front()==i-k){
            dq.pop_front(); 
        }

        while(!dp.empty()&&arr[dq.back()]<arr[i]){
            dq.pop_back();
        }

        dq.push_back(i);
        if (i >= k - 1) ans.push_back(arr[dq.front()]);
    }
    return ans;
}
int main() {
    k = 3, x;
  vector < int > arr = {4,0,-1,3,5,3,6,8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}