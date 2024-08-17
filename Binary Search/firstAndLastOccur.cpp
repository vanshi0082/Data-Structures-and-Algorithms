#include<bits/stdc++.h>
using namespace std;

int firstOccu(vector<int> arr,int target){
    int first = -1;
    int n= arr.size();
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid]>target){
            high= mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return first;
}

int lastOccu(vector<int> arr,int target){
    int last = -1;
    int n= arr.size();
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return last;
}

int main() {
  int target = 13;
  vector < int > arr = {3,4,13,13,13,20,40};
  
  // returning the last occurrence index if the element is present otherwise -1
  cout << " First Ocur at index : "<<firstOccu(arr,target) << "\n";
  cout << " Last Ocur at index : "<<lastOccu(arr,target) << "\n";

  return 0;
}