/*
考点：链表
题目：
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
思路：
定义指针p1，p2分别指向两个链表的头节点，比较两个指针值的大小，若p1节点的值小，则将p1节点接入新链表，指针p1移到下一个节点，反之同理。
注意链表头节点的处理，考虑链表为空时的情况。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL){
            return pHead2;
        }
        if(pHead2==NULL){
            return pHead1;
        }
        ListNode *pHead, *p;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if(p1->val < p2->val){
            p = p1;
            p1 = p1->next;
        }
        else{
            p = p2;
            p2 = p2->next;
        }
        pHead = p;
        while(p1!=NULL && p2!=NULL){
            if(p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = NULL;
        if(p1!=NULL){
            p->next = p1;
        }
        if(p2!=NULL){
            p->next = p2;
        }
        return pHead;
    }
};
