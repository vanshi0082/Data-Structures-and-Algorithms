#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  /*  vector<int> prefix(vector<int>& height){
        int n=height.size();
        vector<int> pree(n,0);
         pree[0] = height[0];
        for(int i=1;i<height.size();i++){
            pree[i]=max(pree[i-1],height[i]);
        }
        return pree;
   }*/ 
    vector<int> sufix(vector<int>& height){
        int n=height.size();
        vector<int> suf(n,0);
         suf[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        return suf;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        int total = 0;
        //vector<int> left=prefix(height);
        vector<int> right=sufix(height);
        int leftMax = height[0];
        for(int i=0;i<n;i++){
            leftMax = max(leftMax,height[i]);
           // int leftMax = left[i];
            int rightMax = right[i];
            total += min(leftMax,rightMax)-height[i];

        }
        return total;
    }
};


int main() {
  vector < int > arr;
  Solution s;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << s.trap(arr) << endl;
}