class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()) {
            s1.push(x);
        }
        else {
            while(!s1.empty()) {
                int k = s1.top();
                s2.push(k);
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()) {
                int k = s2.top();
                s1.push(k);
                s2.pop();
            }
        }
    }
    
    int pop() {
        int k = s1.top();
        s1.pop();
        return k;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()) {
            return true;
        }
        return false;
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