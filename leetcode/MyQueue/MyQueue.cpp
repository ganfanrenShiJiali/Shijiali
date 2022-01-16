//我的解法
class MyQueue {
public:
    stack<int>stk1,stk2;
    int top;
    MyQueue() {

    }
    void push(int x) {
        
        while(!stk1.empty())
        {
            top=stk1.top();
            stk1.pop();
            stk2.push(top);
        }
        stk1.push(x);
        while(!stk2.empty())
        {
            top=stk2.top();
            stk2.pop();
            stk1.push(top);
        }
    }
    
    int pop() {
        int t=stk1.top();
        stk1.pop();
        return t;
    }
    
    int peek() {
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
