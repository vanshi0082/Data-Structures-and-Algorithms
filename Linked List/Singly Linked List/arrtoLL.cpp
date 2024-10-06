#include<bits/stdc++.h>
using namespace std;

struct Node
{   
    public:
    int Data;
    Node* Next;

    public:
    Node(int Data1 , Node* Next1){
        Data = Data1;
        Next = Next1;

    }
     Node(int Data1){
        Data = Data1;
        }
};

Node* arrToLL(vector<int> &arr){
    Node* Head = new Node(arr[0]);
    Node* mover = Head;
    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->Next = temp;
        mover = temp;
       
    }
    return Head;
}

int main(){
    vector<int> arr = {12,23,45};
    arrToLL(arr);
    
    
}