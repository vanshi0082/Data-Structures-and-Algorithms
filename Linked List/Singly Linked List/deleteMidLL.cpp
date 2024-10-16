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

Node* deleteMid(Node* head){
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
   Node* slow = head;
   Node* fast = head;
   fast=head->next->next;

   while(fast!=NULL&&fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
   }
    slow->next=slow->next->next;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5,6};
    cout << "Initial LinkedList : " << endl;
    Node* head =  arrToLL(arr);
    printLL(head);
    cout << "LinkedList After Deleting Mid : " << endl;
    Node* newhead = deleteMid(head);
    printLL(newhead);
}