#include<bits/stdc++.h>
using namespace std;

int rotate(vector<int> arr){
    int firstele = arr[0];
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=firstele;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
  return 0;
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    rotate(arr);
}