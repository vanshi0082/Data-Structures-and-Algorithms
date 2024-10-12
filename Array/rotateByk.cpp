#include<bits/stdc++.h>
using namespace std;

int rotate(vector<int> arr,int k){
    int n= arr.size();
   reverse(arr.begin(),arr.end());
   reverse(arr.begin(),arr.begin()+(k%n));
   reverse(arr.begin()+(k%n),arr.end());
   for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    int k = 4;
    rotate(arr,k);
}