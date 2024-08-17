#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int low,int high,int target){
    int ans;
    if(low<high){
        int mid = (low+high)/2;
        if(arr[mid]>=target){
            ans = arr[mid];
            high = mid -1;
        }
        else{
           low =  mid + 1;
        }
    }
    return ans;
}



int main(){
    vector<int> arr = {12,34,56,78,89};
    int n=  arr.size();
    int target = 55;
    int lowerBound = binarySearch(arr,0,n-1,target);
    cout<< "The LowerBound value of given Target is : "<< lowerBound;
}