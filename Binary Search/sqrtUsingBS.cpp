// You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

/* BRUTE FORCE APPROCH

#include<bits/stdc++.h>
using namespace std;

int find(int n){
    int ans;
    for(int i=0;i<=n;i++){
        if(i*i<=n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

int main(){
    int n = 25;
    int ans = find(n);
    cout << "The Sqrt Is " << ans;
}
*/
#include<bits/stdc++.h>
using namespace std;

int find(int n){
    int low = 0;
    int high = n;
     int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        int value = mid*mid;
       
        if(value == n){
            return ans;
        }
        if(value<n){
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}

int main(){
    int n = 28;
    int ans = find(n);
    cout << "The Sqrt Is " << ans;
}