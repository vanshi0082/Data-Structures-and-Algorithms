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



//using leng of diff:

int getDiff(Node* head1 , Node* head2){
    int l1 = 0;
    int l2 = 0;
    while(head1!=NULL || head2!=NULL){
        if(head1!=NULL){
            ++l1;
            head1=head1->next;
        }
        if(head2!=NULL){
            ++l2;
            head2=head2->next;
        }
    }
    return l1-l2;
}

Node* intersectionUsingL(Node* head1 , Node* head2){
    int diff = getDiff(head1,head2);
    if(diff<0){
        while(diff!=0){
        diff++;
        head2 = head2->next;
        }
    }
    else{
        while(diff!=0){
        diff--;
        head1 = head1->next;
        }
    }
    while(head1!=NULL){
        if(head1 == head2){
            return head1;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return head1;
}

Node* intersectionUsingPointer(Node* head1,Node* head2){
   if(head1==NULL||head2==NULL){
    return NULL;
   }
   Node* temp1 = head1;
   Node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    
        if(temp1==temp2){
        return temp1;
        }
        if(temp1==NULL){
        temp1=head2;
        }
        if(temp2==NULL){
        temp2=head1;    
        }
    }
    return temp1;
}

int main() {
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;

    cout<<"List1: "; printLL(head1);
    cout<<"List2: "; printLL(head2);
   // cout << "The Intersection of the LinkedLists is  : " << endl;
    Node* answerNode = intersectionUsingPointer(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->data<<endl;
    return 0;
}
