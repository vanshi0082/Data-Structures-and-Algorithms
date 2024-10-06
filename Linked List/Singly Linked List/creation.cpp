#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int Data;
    Node* Next;

    public:
    Node(int Data1,Node* Next1){
        Data = Data1;
        Next = Next1;
    }

    public:
    Node(int Data1){
        Data = Data1;
        Next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,3,4,5};
    Node* x = new Node(arr[0]);
    cout<<x<<"\n";
    cout<<x->Data<<"\n";
}
