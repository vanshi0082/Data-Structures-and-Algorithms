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
//just updatinng the pointers
Node* SegregatetoOddEVen(Node* head){
     if (head == nullptr || head->Next == nullptr)
            return head;
        Node* odd = head;
        Node* even = head->Next;
        Node* store = even;

        while(even!=nullptr&&even->Next!=nullptr){
            odd->Next = odd->Next->Next;
            even->Next = even->Next->Next;
            odd = odd->Next;
            even= even->Next;
        }
        odd->Next = store;
        return head;
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

int main() {
    vector<int> arr = {1,2,3,4};
    cout << "Initial LinkedList : " << endl;
    Node* head =  arrToLL(arr);
    printLL(head);
    Node* newHead = SegregatetoOddEVen(head);
    cout << "LinkedList After Segregration : " << endl;
    printLL(newHead);
    return 0;
}
