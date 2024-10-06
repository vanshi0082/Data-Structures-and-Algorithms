#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to calculate the length of a linked list
int searchInLL(Node* head,int val){
    Node* temp = head;
    
    while(temp!=nullptr){
        if(temp->data==val){
           return 1;
        }
        else{
        temp=temp->next;
        }
    }
    return 0;
}

int main() {
   Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int val = 2;  // Element to be checked for presence in the linked list

    // Call the checkifPresent function and print the result
    int ans = searchInLL(head,val);
    if(ans == 1){
        cout<<"The Node is founded"<<"\n";
    }
    else{
         cout<<"The Node is not founded"<<"\n";
    }

    return 0;
}