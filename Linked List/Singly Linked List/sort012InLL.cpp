#include<bits/stdc++.h>
using namespace std;

struct Node {   
    public:
    int Data;
    Node* Next;

    Node(int Data1) {
        Data = Data1;
        Next = nullptr;
    }
};

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->Data << " ";
        head = head->Next;
    }
    cout << endl;
}

Node* arrToLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* Head = new Node(arr[0]);
    Node* mover = Head;
    
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->Next = temp;
        mover = temp;
    }
    
    return Head;
}
Node* sortLL(Node* head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->Data==0){
            zeroTail->Next = temp;
            zeroTail=zeroTail->Next;
        }
        else if(temp->Data==1){
            oneTail->Next=temp;
            oneTail=oneTail->Next;
        }
        else{
            twoTail->Next=temp;
            twoTail=twoTail->Next;
        }
        temp = temp->Next;
    }

    zeroTail->Next=oneHead->Next?oneHead->Next:twoHead->Next;
    oneTail->Next=twoHead->Next;
    twoTail->Next=NULL;

    Node* newHead = zeroHead->Next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

int main() {
    vector<int> arr = {1,2,0,0,1,2,0,1,2,1,0};
    cout << "Initial LinkedList : " << endl;
    Node* head =  arrToLL(arr);
    printLL(head);
    Node* newHead = sortLL(head);
    cout << "Sorted Linked List : " << endl;
    printLL(newHead);
    return 0;
}
