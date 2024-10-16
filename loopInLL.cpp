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

bool detectCycle(Node* head){
    unordered_map<Node* , int> m;
    Node* temp = head;

    while(temp!=NULL){
        if(m.find(temp)!=m.end()){
            return true;
        }
        m[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//USING TORTOISE ALGO

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast= fast->next->next;

        if(slow==fast){
            return true;
        }
        
    }
    return false;
}

int main() {
     
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
}
