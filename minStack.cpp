class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> st;
    long minVal = 0;
    MinStack() {
    }
    
    void push(int val) {
     if(st.empty()){
         st.push(val);
         minVal = val;
     }
    else{
     if(val > minVal){
         st.push(val);
     }
     else{
         st.push(val + (val - minVal));
         minVal = val;
     }
        }
    }
    
    void pop() {
        if(st.top() < minVal){
            minVal = minVal + (minVal - st.top());    
        }
        st.pop();
    }
    
    int top() {
      if(st.top() < minVal){
          return (int)minVal;
      }  
      else{
          return (int) st.top();
      }
    }
    
    int getMin() {
       return (int)minVal; 
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
