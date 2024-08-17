#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
   

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2,3,4,5,6,13,24,78};
    int target = 24;
    int index = binarySearch(arr,target);
    cout <<"The element is present on the index : " <<index;
    return 0;
}