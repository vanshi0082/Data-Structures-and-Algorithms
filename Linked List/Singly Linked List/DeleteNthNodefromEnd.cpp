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

//L-N+1

/* BRUTE FORCE APPROCH

Node* DeleteNthNodefromEnd(Node* head,int N){
    int L = 0;
    Node* temp = head;

    if (head == NULL) {
        return NULL;
    }

    while(temp!=NULL){
        L++;
        temp=temp->next;
    }
    if (L == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    int pos = L-N;
    temp = head;
    while(temp!=NULL){
        pos--;
        if(pos==0){
            break;
        }
        temp=temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}
*/

Node* DeleteNthNodefromEnd(Node* head,int N){
    Node* slow = head;
    Node* fast = head;

    for(int i=0;i<N;i++){
        fast = fast->next;
    }
    if(fast == NULL){
        return head ->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    cout << "Initial LinkedList : " << endl;
    Node* head =  arrToLL(arr);
    printLL(head);
    cout << "LinkedList After Deleting the Nth Node From The End : " << endl;
    Node* newhead = DeleteNthNodefromEnd(head, N);
    printLL(newhead);
}