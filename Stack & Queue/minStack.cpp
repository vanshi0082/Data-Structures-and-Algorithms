#include<bits/stdc++.h>
using namespace std;

class Stack{
    stack<long long> st;
    long long mini = INT_MAX;

    public:
    void push(int x){
        if(st.empty()){
            mini = x;
            st.push(x);
        }
        else{
        if(x<mini){
            mini = (2*mini)-x;
            st.push(mini);
        }
        else{
            st.push(x);
        }
        }
    }

    int pop(){
        if(st.empty()) return 0;
        long long ele = st.top();
        st.pop();

        if(ele<mini){
            mini = (2*mini)-ele;
        }
        return ele;
    }

    int top(){
        if (st.empty()) return -1;
        long long ele = st.top();
        if(ele<mini) return mini;
        return ele;
    }
    int getMin(){
        return mini;
    }
};




int main() {
 Stack s;
  s.push(4);
  s.push(5);
  cout << "The element poped is " << s.pop() << endl;
  s.push(6);
  cout << "The top of the stack is " << s.top() << endl;
  
   cout << "The minimun of the stack is " << s.getMin() << endl;

}


/*
class Stack{
    stack<pair<int,int>> st;
    
    public:
    void Push(int x){
        int mini;
        if(st.empty()){
            mini = x;
        }
        else{
            mini = min(st.top().second,x);
        }
        st.push({x,mini});
    }
    int pop(){
        int val = st.top().first;
        st.pop();
        return val;
    }
    int top(){
        int val = st.top().first;
        return val;
    }
    int getMin(){
        return st.top().second;
    }


};
*/

int main() {
 Stack s;
  s.Push(3);
  s.Push(4);
  cout << "The element poped is " << s.pop() << endl;
  s.Push(5);
  cout << "The top of the stack is " << s.top() << endl;
  
   cout << "The minimun of the stack is " << s.getMin() << endl;

}