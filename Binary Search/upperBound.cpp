#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
   int ans = n;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>target){
            ans = mid;
            high = mid - 1;
        }
        else{
           low =  mid + 1;
        }
    }
    return ans;
}

int main(){
     vector<int> arr = {3, 5, 8, 9, 15, 19};
    int target = 9;
    int index = binarySearch(arr,target);
    cout <<"The upper bound is the index: " <<index;
    return 0;
}