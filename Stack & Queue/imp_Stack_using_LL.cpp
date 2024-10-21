#include<bits/stdc++.h>
using namespace std;

class stackNode{
    public:
    int data;
    stackNode* next;
    int size;
    stackNode(int d){
        data=d;
        next=NULL;
    }
};

class Mystack {
    public:
    stackNode * top;
    int size;
    stack() {
        top=NULL;
        size=0;
    }
    void stackPush(int x){
        stackNode * ele = new stackNode(x);
        ele -> next = top;
        top=ele;
        cout << "Element pushed" << "\n";
        size++;
    }
    int stackPop(){
        if(top==NULL){
            return -1;
        }
        int topData = top->data;
        stackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }
    int stackSize(){
        return size;
    }
    bool stackIsEmpty(){
        return top==NULL;
    }
    int stackPeek(){
        if(top==NULL){
            return -1;
        }
        return top->data;
    }
    void printStack(){
        stackNode* curr = top;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};

int main() {
  Mystack s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}