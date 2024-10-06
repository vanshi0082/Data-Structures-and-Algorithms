#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
        back = back1; // Addition of 'back' pointer for the doubly linked list.
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr; // Similar to a singly linked list.
        back = nullptr; // Addition of 'back' pointer initialization.
    }
};

void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

Node* convert(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int lengthOfLinkedList(Node* head) {
    Node* temp = head;
    int cnt = 0;
    // Traverse the linked list and count nodes
    while (temp != NULL) {
        temp = temp->next;
        cnt++; // increment cnt for every node traversed
        
    }
    return cnt;
}

Node* deleteHead(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    Node* tail = head;

    while(tail->next != nullptr){
        tail = tail->next;    
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

int main(){
    vector<int> arr = {2,4,56,6};
    Node* head = convert(arr);
    printf("\nThe Linked List : ");
    print(head);
    printf("\nDeleting Head : ");
    head = deleteHead(head);
    print(head);
    printf("\nDeleting Tail : ");
    head = deleteTail(head);
    print(head);
    
}