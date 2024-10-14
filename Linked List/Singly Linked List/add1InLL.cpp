#include<bits/stdc++.h>
using namespace std;

struct Node {   
    public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

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

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp=front;
    }
    return prev;
}

Node* add(Node* head){
    head = reverseLL(head);
    int carry = 1;
    Node* curr=head;
    while(curr!=NULL){
       curr->data = carry + curr->data;
        if(curr->data<10){
            carry =0;
            break;
        }
        else{
            curr->data = 0;
            carry=1;
        }
        curr=curr->next;
    }   
if(carry==1){
    Node* newNode = new Node(1);
    head = reverseLL(head);
    newNode->next = head;
    return newNode;
}
else{
    head = reverseLL(head);
    return head;
    }
}


int main() {
    vector<int> arr = {9,9,9};
    cout << "Initial LinkedList : " << endl;
    Node* head =  arrToLL(arr);
    printLL(head);
    cout << "After adding to the 1 in the LinkedList ans is " << endl;
    Node* newhead = add(head);
    printLL(newhead);
}

/*
int addHelper(Node* temp){
if(temp==NULL){
return 1;
}
int carry = addHelper(temp->next);
temp->data += carry;
if(temp_data < 10) return 0;
return 1;
}

Node *add(Node* head){
    int carry = addHelper(head);
    if(carry==1){
        Node* newNode = new NOde(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
*/