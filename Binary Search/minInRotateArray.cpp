#include<bits/stdc++.h>
using namespace std;


int findMin(vector<int> arr){
    int n = arr.size();
    int ans = INT_MAX;
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            ans = min(arr[low],ans);
            low = mid+1;
        }
        else{
            ans = min(arr[mid],ans);
            high = mid -1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;

}