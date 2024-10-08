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

Node* insertAtTail(Node* head,int val){
    Node* newNode = new Node(val);
    if(head==nullptr){
        return newNode;
    }

    Node* tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->back= tail;
    return head;
}

Node* insertAtHead(Node* head , int val){
    Node* newNode = new Node(val);
    if(head==nullptr){
        return newNode;
    }

    Node* temp = newNode;
    temp->next = head;
    head->back = temp;
    return newNode;
}

Node* insertAtKthIndex(Node* head , int k,int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* kNode = head;
    while(kNode->next!=NULL){
        cnt++;
        if(cnt==k) break;
        kNode = kNode->next;
    }
    Node* front = kNode->next;
    Node* prev = kNode->back;

    if(front==NULL&&prev==NULL){
        return newNode;
    }
    else if(prev==NULL){
        return insertAtHead(head,val);
    }
    else if(front==NULL){
        return insertAtTail(head,val);
    }
    else{
       newNode->next = front;
       newNode->back = prev;
       front->back = newNode;
       prev->next = newNode;
    }
    return head;
    
}

Node* insertBeforeKthIndex(Node* head , int k,int val){
     if(k==1){
        // K = 1 means node has to be insert before the head
        return insertAtHead(head, val);
    }
    
    // temp will keep track of the node
    Node* temp = head;
    
    // count so that the Kth element can be reached
    int count = 0;
    while(temp!=NULL){
        count ++;
        // On reaching the Kth position, break out of the loop
        if(count == k) break;
        // keep moving temp forward till count != K
        temp = temp->next;
    }
    // track the node before the Kth node
    Node* prev = temp->back;
    
    // create new node with data as val
    Node* newNode = new Node(val, temp, prev);
    
    //join the new node in between prev and temp
    prev->next = newNode;
    temp->back = newNode;
    
    // Set newNode's pointers to prev and temp
    newNode->next = temp;
    newNode->back = prev;
    
    // Return the head of the updated doubly linked list
    return head;
}

void insertBeforeNode(Node*node, int val){
    // Get the node before the given node
    Node* prev = node->back;
    
    // Create a new node with the given val
    Node* newNode = new Node(val, node, prev);
    
    // Connect the newNode to the doubly linked List
    prev->next = newNode;
    node->back = newNode;
    
    // void function to just update
    return;
}


int main(){
  vector<int> arr = {12, 5, 8, 7, 4,3,56};
    Node* head = convert(arr);
    cout << "Doubly Linked List Initially: " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;

    // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    cout << endl << "Doubly Linked List After Inserting at Head with value 1: " << endl;
     head = insertAtHead(head, 1);
    print(head);

    cout << endl << "Doubly Linked List After Inserting at Kth Index with value 4: " << endl;
     head = insertAtKthIndex(head, 3,466);
    print(head);

    cout << endl << "Doubly Linked List After Inserting Before Kth Index with value 70: " << endl;
     head = insertBeforeKthIndex(head, 3,70);
    print(head);

    cout << endl << "Doubly Linked List After Inserting Before Kth Index with value 70: " << endl;
    insertBeforeNode(head->next->next,20);
    print(head);
    return 0;
}