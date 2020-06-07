### 题目
[面试题30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 

示例:MinStack minStack = new MinStack();

minStack.push(-2);

minStack.push(0);

minStack.push(-3);

minStack.min();   --> 返回 -3.

minStack.pop();

minStack.top();      --> 返回 0.

minStack.min();   --> 返回 -2.

 提示：
 各函数的调用总次数不超过 20000 次
 
 
### 思路
1. 定义两个栈s,s_min分别记录栈内元素及栈内最小元素。s_min栈顶记录s栈内最小值
2. 入栈操作：若s栈为空，则将元素x分别压入s和s_min；否则，将元素x压入s，并判断s_min栈顶元素和x的大小，将栈顶元素和x的最小值压入s_min中。
3. 出栈操作：若s和s_min非空，分别弹出s和s_min的栈顶元素
4. top：返回栈s的栈顶元素
5. min：返回栈s_min的栈顶元素

### 复杂度分析
- 时间复杂度O(1)：四个函数的时间复杂度都都是常数级别
- 空间复杂度O(N)：当有N个待入栈元素时，s_min最差情况下需要存储N个元素，需要O(N)额外空间

### 代码
```cpp

class MinStack {
private:
    stack<int> s;
    stack<int> s_min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(s.empty()){
            s_min.push(x);
            s.push(x);      
        }
        else{
            int tmp_min = s_min.top();
            s.push(x);
            if(tmp_min<=x){
                s_min.push(tmp_min);
            }
            else{
                s_min.push(x);
            }
        }
        return;
    }
    
    void pop() {
        if(s.empty()&&s_min.empty()){
            return;
        }
        else{
            s.pop();
            s_min.pop();
            return;
        }
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }
        return s.top();
    }
    
    int min() {
        if(s_min.empty()){
            return -1;
        }
        return s_min.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */




```

### 测评
执行用时 :36 ms, 在所有 C++ 提交中击败了78.26%的用户

内存消耗 :15.2 MB, 在所有 C++ 提交中击败了100.00%的用户


