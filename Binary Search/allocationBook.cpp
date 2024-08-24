#include<bits/stdc++.h>
using namespace std;

int check(vector<int> books,int pages){
    int student = 1;
    int noPages = 0;
    int n = books.size();
    for(int i = 0;i<n;i++){
        if(noPages+books[i]<=pages){
            noPages+=books[i];
        }
        else{
            student++;
            noPages = books[i];
        }
    }
    return student;

}

int possibeAns(vector<int> books,int student){
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);
    int n = books.size();
    if(student>n){
        return -1;
    }

    while(low<=high){
        int mid = (low+high)/2;
        int ans = check(books,mid);

        if(student < ans){
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
    vector<int> books = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = possibeAns(books, m);
    cout << "The answer is: " << ans << "\n";
    return 0;

}