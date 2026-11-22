class MinStack {
public:
    MinStack() { 

    }

    stack<pair<int, int>> st;
    
    void push(int value) {   
        int newMin = value;

        if(!st.empty()){
            newMin = min(value, getMin());
        }

        st.push({value, newMin});
    }
    
    void pop() {       
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};