/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> s1;
    vector<int> sm;
    MinStack() {

    }

    void push(int val) {
        s1.push_back(val);
        if (sm.size() > 0 && sm[sm.size()-1] < val)
        {
            sm.push_back(sm[sm.size()-1]);
        }
        else
        {
            sm.push_back(val);
        }
        
    }
    
    void pop() {
        s1.pop_back();
        sm.pop_back();
    }
    
    int top() {
        return s1[s1.size()-1];
    }
    
    int getMin() {
        return sm[sm.size()-1];
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
// @lc code=end

