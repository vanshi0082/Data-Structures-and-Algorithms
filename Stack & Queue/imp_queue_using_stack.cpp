#include<bits/stdc++.h>

using namespace std;

class Queue {
  stack < int > s1;
  stack < int > s2;
  public:
    void Push(int x) {
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
      s1.push(x);
      while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }
    }
  int Pop() {
      int n = s1.top();
    s1.pop();
    return n;
  }
  int Top() {
    return s1.top();
  }
  int Size() {
    return s1.size();
  }
};

int main() {
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.Size() << endl;
}