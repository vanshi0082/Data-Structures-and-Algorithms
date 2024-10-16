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

void insertNode(Node* &head,int val) {
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}


void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* intersection(Node* head1 ,Node* head2){
    unordered_set<Node*> st;
    while(head1 != NULL){
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2) != st.end()){
            return head2;
        }
        head2 = head2->next;
    }
    return NULL;
}

//USING HASHING



//USING TORTOISE ALGO

int findLength(Node* slow,Node* fast){
    int cnt = 1;
    fast=fast->next;
    while(fast!=slow){
        cnt++;
        fast=fast->next;
    }
    return cnt;

}

int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt = 0;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;

        if(slow==fast){
            return findLength(slow,fast);
            
        }
    }
    return 0;
}


int main() {
     
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
   
}
