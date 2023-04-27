class MinStack {
public:
    stack<int> st;
    map<int,int> mp;
    
    MinStack() {
        ;
    }
    
    void push(int val) {
        st.push(val);
        if(mp.find(val)!=mp.end()){
            mp[val]++;
        }
        else{
            mp[val]=1;
        }
    }
    
    void pop() {
        int temp_stack=st.top();
        int temp=mp[temp_stack];
        if(temp==1){
            mp.erase(temp_stack);
        }
        else{
            mp[temp_stack]--;
        }
        
        st.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return mp.begin()->first;
        
    }
// private:
    // stack<int> st;
    // map<int,int> mp;
    // int count=0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
