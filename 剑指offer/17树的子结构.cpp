/*
考点：
题目：
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
思路：
首先判断B是不是A的子结构，若不是，判断B是不是A的左子树的子结构，若不是，继续判断B是不是A的右子树的子结构。
对于IsSubtree函数：
若B和A的当前节点值相等，则进一步判断B和A的左节点是否一致以及B和A的右节点是否一致。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL){
            return false;
        }
        return IsSubtree(pRoot1,pRoot2) ||HasSubtree(pRoot1->left,pRoot2) ||HasSubtree(pRoot1->right,pRoot2); //注意
        
    }
    bool IsSubtree(TreeNode* p1, TreeNode* p2)
    {
    	if(p2==NULL){
    		return true;
    	}
    	if(p1==NULL){
    		return false;
    	}
    	if(p1->val == p2->val)
    	{
    		return IsSubtree(p1->left,p2->left) && IsSubtree(p1->right,p2->right);
    	}
    	else{
    		return false;
    	}
    }
};
