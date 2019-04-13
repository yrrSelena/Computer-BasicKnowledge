/*
考点：链表
题目：
输入一个链表，反转链表后，输出新链表的表头。
思路：
定义前、中、后三个指针p1,p2,p3，p3用于指向原链表的下一个节点，每次都修改p2的next指针，使其指向前面一个节点p1，直至p3指向空（遍历完链表中的所有节点）
此时p2作为新链表的表头指针，最后将原链表的头节点的next指向NULL
注意考虑链表为空以及链表中只有一个节点的情况。
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNewHead;
        if(pHead == NULL || pHead->next == NULL){
            return pHead;
        }
        ListNode* p1 = pHead;
        ListNode* p2 = pHead->next;
        ListNode* p3 = p2->next;
        p2->next = p1;
        while(p3 != NULL){
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
        }
        pHead->next = NULL;
        return p2;
    }
};
