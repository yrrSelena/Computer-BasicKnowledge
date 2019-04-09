/*
题目：
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
思路：
1）首先创建一个栈
2）从头到尾遍历链表，并将数据压入栈中
3）将栈顶数据依次弹出，存入ArrayList中
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> arr;
        if(head == NULL){
            return arr;
        }
        ListNode* p = head;
        while(p!=NULL){
            s.push(p->val);
            p = p->next;
        }
        while(!s.empty()){
            arr.push_back(s.top());
            s.pop();
        }
        return arr;
    }
};
