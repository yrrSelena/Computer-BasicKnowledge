/*
题目：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
class Solution
{
public:
    void push(int node) {
        while(!stack2.empty()){
            int tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        if(!stack2.empty()){
            int node =stack2.top();
            stack2.pop();
            return node;
        }
        else{
            return NULL;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
