//Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROCH
int find(vector<int> arr,int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

int main(){
    vector<int> arr = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = find(arr, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}



