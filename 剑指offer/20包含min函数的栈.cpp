/*
题目：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
思路：
定义两个栈s和smin，分别存放原数据和最小值
每次入栈，s正常操作；对于smin，要将当前数据与栈顶数据进行比较，若当前数据更小，则将当前数据压入smin，否则将栈顶数据压入smin
smin的栈顶保存当前栈中的最小值
*/
class Solution {
public:
    void push(int value) {
    	s.push(value);
        if(smin.empty()){
        	smin.push(value);
        }
        else{
        	int tmp = smin.top();
        	if(tmp < value){
        		smin.push(tmp);
        	}
        	else{
        		smin.push(value);
        	}
        }
    }
    void pop() {
        s.pop();
        smin.pop();
    }
    int top() {
    	return s.top();
    	
    }
    int min() {
    	return smin.top();
    }
private:
    stack<int> s;
    stack<int> smin;
    
};
