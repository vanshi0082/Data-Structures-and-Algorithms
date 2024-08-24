#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> arr,int cows,int dist){
     int cntCow = 1;
    int last = arr[0];
    int n = arr.size();
    for(int i=0;i<=n;i++){
        if(arr[i]-last>=dist){
            cntCow++;
            last = arr[i];
        }
    }
    if(cntCow>=cows){
        return true;
    }
    else{
        return false;
    }
}

int findPossibleAns(vector<int> arr,int cows){
   
    int maxi = *max_element(arr.begin(),arr.end());
    int mini = *min_element(arr.begin(),arr.end());
    int range = maxi-mini;

   int low = 1;
   int high = range;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(arr,cows,mid))
            low = mid + 1;
        else{
            high = mid -1;
        }
    }
    return high;
    
        
}

int main(){
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    int ans = findPossibleAns(arr, cows);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}