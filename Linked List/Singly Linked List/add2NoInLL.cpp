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

Node* add(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = 0;
        if (l1 != NULL) {
            sum += l1->Data;
            l1 = l1->Next;
        }
        if (l2 != NULL) {
            sum += l2->Data;
            l2 = l2->Next;
        }

        sum += carry;
        carry = sum / 10;

        Node* node = new Node(sum % 10);
        temp->Next = node;
        temp = temp->Next;
    }
    
    return dummy->Next;
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
    // Make sure that arr1 and arr2 contain single digits to represent the number
    vector<int> arr1 = {1, 2, 3}; // Represents 321 (in reverse order)
    vector<int> arr2 = {9, 8, 7}; // Represents 789 (in reverse order)
    
    Node* l1 = arrToLL(arr1);
    Node* l2 = arrToLL(arr2);
    
    Node* addition = add(l1, l2);
    
    cout << "New addition linked list: ";
    printLL(addition);  // Output should represent the sum of 321 + 789 (in reverse)
}
