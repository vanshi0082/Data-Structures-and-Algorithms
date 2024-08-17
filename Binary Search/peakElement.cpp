#include<bits/stdc++.h>
using namespace std;

/*brute force approch
int find(vector<int> arr){
    int n  = arr.size();
    for(int i=0;i<n;i++){
        if(i=n-1 || arr[i]>arr[i+1] && i=0 || arr[i]>arr[i-1]){
            return arr[i];
        }
       
    }
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = find(arr);
    cout << "The peak element is : " << ans << "\n";
    return 0;
}*/

int find(vector<int> arr){
    int n = arr.size();
    if(n==1){
        return arr[0];
    }
    if(arr[0]>arr[1]){
        return arr[0];
    }
    if(arr[n-1]>arr[n-2]){
        return arr[n-1];
    }
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            return arr[mid];
        }
        else if(arr[mid]>arr[mid-1]){
            low = mid +1;
        }
        else if(arr[mid]>arr[mid+1]){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = find(arr);
    cout << "The peak element is`: " << ans << "\n";
    return 0;
}