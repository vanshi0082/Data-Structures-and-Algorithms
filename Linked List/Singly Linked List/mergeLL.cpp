#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int a) {
            data = a;
            next = NULL;
        }
};
//utility function to insert node at the end of the list
Node* arrToLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* Head = new Node(arr[0]);
    Node* mover = Head;
    
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    
    return Head;
}

Node* merge(Node* head1 , Node* head2){
    Node* l1 = head1;
    Node* l2 = head2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(l1!=NULL && l2!=NULL){
        if(l1->data<l2->data){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
        else{
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
        
    }
    if(l1){
        temp->next=l1;
    }
    else{
        temp->next=l2;
    }
   
    return dummyNode->next;
}

void printList(Node* head) {
    while(head->next != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    } 
    cout<<head->data<<endl;
    return;
}

int main() {
    vector<int> arr1 = {1, 3, 5};
     vector<int> arr2 = {2,4,7,8,9};
    Node* head1 = arrToLL(arr1);
    Node* head2 = arrToLL(arr2);
    cout << "Original Linked List 1: ";
    printList(head1);
    cout << "Original Linked List 2: ";
    printList(head2);
 
    Node* newHead = merge(head1,head2);//calling function for rotating right of the nodes by k times
    cout << "Merged Linked List: ";
    printList(newHead);//list after rotating nodes
    return 0;
}