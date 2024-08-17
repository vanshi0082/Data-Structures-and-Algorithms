#include<bits/stdc++.h>
using namespace std;

int find(vector<int> arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return true;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
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
    return false;

}

int main(){
   vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
   int target = 30;
    bool ans = find(arr,target);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}