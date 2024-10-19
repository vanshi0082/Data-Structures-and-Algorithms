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

Node* getNode(Node* temp,int k){
    k -= 1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* reverseWithKGroup(Node* head,int k){
    Node* temp = head;
    Node* prev = NULL;
    
    while(temp!=NULL){
        Node* kTHNode = getNode(temp,k);
        if(kTHNode==NULL){
            if(prev){
                prev -> next = temp;
            }
            break;
        }
        Node* next = kTHNode->next;
        kTHNode->next = NULL;
        reverseLL(temp);

        if(temp==head){
            head = kTHNode;
        }
        else{
            prev -> next = kTHNode;
        }
        prev = temp;
        temp = next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = arrToLL(arr);
    cout << "Original Linked List: ";
    printLL(head);

    // Reverse the linked list
    head = reverseWithKGroup(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLL(head);

    return 0;
}