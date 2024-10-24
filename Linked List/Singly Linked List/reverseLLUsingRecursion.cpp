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

    if(head==NULL||head->next==NULL){
        return head;
    }

   Node* newHead = reverseLL(head->next);
   Node* front = head->next;
   front->next = head;
   head->next=NULL;

    return newHead;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Initial LinkedList : " << endl;
    Node* head =  arrToLL(arr);
    printLL(head);
    cout << "Reversed LinkedList : " << endl;
    Node* newhead = reverseLL(head);
    printLL(newhead);
}