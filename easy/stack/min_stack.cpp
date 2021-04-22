/*Question Link: https://leetcode.com/problems/min-stack/*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>main_stack,min_stack;
    MinStack() {
        while(!main_stack.empty()){
            main_stack.pop();
        }
        
        while(!min_stack.empty()){
            min_stack.pop();
        }
    }
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty() || min_stack.top()>=val){
            min_stack.push(val);
        }
    }
    
    void pop() {
        if(!min_stack.empty() && (min_stack.top() == main_stack.top())){
            min_stack.pop();
        }
        
        if(!main_stack.empty()){
            main_stack.pop();
        }
    }
    
    int top() {
        if(!main_stack.empty())
            return main_stack.top();
        else
            return -1;
    }
    
    int getMin() {
        if(!min_stack.empty())
            return min_stack.top();
        else
            return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */