/*
考点：链表
题目：
输入一个链表，输出该链表中倒数第k个结点。
思路：
定义两个指针pfast和pslow，指针pfast比pslow快k-1步，当pfast指针指向最后一个节点时，pslow指针指向倒数第k个节点
注意考虑链表为空的情况，以及判断链表中是否有k个节点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k == 0 || pListHead == NULL){
            return NULL;
        }
        ListNode* pfast = pListHead;
        int i = 0;
        while(i < k-1 && pfast->next != NULL){
            pfast = pfast->next;
            i++;
        }
        if(i < k-1){
            return NULL;
        }
        else{
            ListNode* pslow = pListHead;
            while(pfast->next != NULL){
                pslow = pslow->next;
                pfast = pfast->next;
            }
            return pslow;
        }
    }
};
