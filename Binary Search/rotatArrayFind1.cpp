#include<bits/stdc++.h>
using namespace std;

int find(vector<int> arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid]<=arr[high]){
                if(arr[mid]<=target && target <= arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid -1;
                }
            }
        }
    }
    return -1;

}

int main(){
   vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
   int target = 1;
    int ans = find(arr,target);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}