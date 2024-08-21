// Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

#include<bits/stdc++.h>
using namespace std;

//Power exponential method
//mid^n
int power(int mid , int n){
    long long ans = 1;
    while(n>0){
        if(n%2==1){
            ans = ans * mid;
            n = n-1;
        }
        else{
            mid = mid * mid;
            n = n/2;
        }
    }
    return ans;
}


int find(int m , int n){
    int low = 1;
    int high = m;
    while(low<=high){
        int mid = (low + high) /2;
        int value = power(mid,n);
        if(m == value){
            return mid;
        }
        else if(value<m){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}
int main(){
   int n = 3, m = 27;
    int ans = find(m, n);
    cout << "The answer is: " << ans << "\n";
    return 0;
}