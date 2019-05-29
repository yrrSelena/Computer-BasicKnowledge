/*
题目：
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
思路：
利用栈进行计算，遇到数字，将其压入栈中；遇到运算符，将栈顶两个元素弹出并进行计算，再将计算结果压入栈中
直至遍历完所有的tokens，栈顶元素即为所求结果
【注】考虑数字的正负号问题
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int a, b;
        for(int i = 0; i< tokens.size(); i++){
            if(tokens[i]=="+")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(tokens[i]=="-"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(tokens[i]=="*"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if(tokens[i]=="/"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                int x = 0;
                int j = 0;
                if(tokens[i][0]=='-')
                    j = 1;
                for(; j< tokens[i].size(); j++){
                    x = x*10+tokens[i][j]-'0';
                }
                if(tokens[i][0]=='-')
                    x = -x;
                s.push(x);
            }
            
        }
        return s.top();
    }
};
