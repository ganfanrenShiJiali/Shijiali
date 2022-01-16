class MyStack {
public:
    queue<int>q1,q2;
    int t;
    MyStack() {
    }
    
    void push(int x) {
        /*while(!q1.empty())
        {
            t=q1.front();
            q1.pop();
            q2.push(t);
        }
        q1.push(x);
        while(!q2.empty())
        {
            int t=q2.front();
            q2.pop();
            q1.push(t);
        }*/
        q2.push(x);
        while(!q1.empty())
        {
            t=q1.front();
            q1.pop();
            q2.push(t);
        }
        queue<int>tmp=q2;
        q2=q1;
        q1=tmp;//共需要n次出队操作，n+1次入队操作，时间复杂度O(n)空间复杂度O(n)
    }
    //以下均为时间复杂度O(1)空间复杂度O(1)
    int pop() {
        t=q1.front();
        q1.pop();
        return t;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
