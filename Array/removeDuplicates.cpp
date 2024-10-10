#include<bits/stdc++.h>

using namespace std;
int removeDuplicatesUsingSet(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

//USING POINTERS

int removeDuplicatesUsingPointers(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicatesUsingSet(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
  int arr2[] = {3,3,5,5,5,8};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  int k2 = removeDuplicatesUsingPointers(arr2, n2);
  cout << endl <<"The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k2; i++) {
    cout << arr2[i] << " ";
  }
  
}

