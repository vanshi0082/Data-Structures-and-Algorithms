#include<bits/stdc++.h>
using namespace std;

int find2(vector<int> weights,int cap){
    int day = 1;
    int load = 0;
    int n = weights.size();
    for(int i=0;i<n;i++){
        if(load+weights[i]>cap){
            day= day+1;
            load = weights[i];
        }
        else{
            load = load+weights[i];
        }
    }
    return day;
}

int find(vector<int> weights,int days){
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int NoDay = find2( weights,mid);
        if(NoDay<=days){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
        
    }
    return low;
}

int main(){
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = find(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
