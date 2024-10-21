#include<bits/stdc++.h>
using namespace std;

class QueueNode{
    public:
    int data;
    QueueNode* next;
    QueueNode(int data1){
        data=data1;
        next = nullptr;
    }
};
QueueNode* front = nullptr;
QueueNode* rare = nullptr;

class Queue{
    public:
    int size = 0;
    bool Empty(){
        return front == nullptr;
    }
    void Enqueue(int data){
        QueueNode* temp;
        temp = new QueueNode(data);
        if(temp==nullptr){
             cout << "Queue is Full" << endl;
        }
        else{
            if(front==nullptr){
                front = temp;
                rare=temp;
            }
            else{
                rare->next=temp;
                rare=temp;
            }
            cout<< data <<" Inserted into Queue "<<endl;
            size++;
        }
    }
    void Dequeue(){
        if(front==nullptr){
            cout << "Queue is Empty" << endl;
        }
        else{
             cout<<front->data <<" Removed From Queue"<<endl;
             QueueNode *temp = front;
             front=front->next;
             delete temp;
             size--;
        }
    }
    int Peek(){
        if(Empty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            return front->data;
        }
    }
};

int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
    return 0;
}   