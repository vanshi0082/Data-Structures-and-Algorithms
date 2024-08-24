#include<bits/stdc++.h>
using namespace std;

int check(vector<int> arr,int mwall){
    int painter = 1;
    int wall = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        if(wall+arr[i]<=mwall){
            wall+=arr[i];
        }
        else{
            painter++;
            wall = arr[i];
        }
    }
    return painter;

}

int possibeAns(vector<int> arr,int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int n = arr.size();
    if(k>n){
        return -1;
    }

    while(low<=high){
        int mid = (low+high)/2;
        int ans = check(arr,mid);

        if(k < ans){
            low = mid+1;
        }
        else{
           high = mid -1;
        }
    }
    return low;
}
/*
    for(int i = low ;i<= high;i++){
        int ans = check(books,i);
        if(ans == student){
            return i;
        }
    }
    return -1;
}
*/

int main(){
   vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = possibeAns(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;

}