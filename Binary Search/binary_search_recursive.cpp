#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int low,int high,int target){
    if(low<high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            binarySearch(arr,low,mid-1,target);
        }
        else{
            binarySearch(arr,mid+1,high,target);
        }
    }
    return -1;
}



int main(){
    vector<int> arr = {12,34,56,78,89};
    int n=  arr.size();
    int target = 56;
    int index = binarySearch(arr,0,n-1,target);
    cout<< "Target is present on the index :"<< index;
}