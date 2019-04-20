/*
题目：
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

思路：
递归遍历每个节点，将每个节点的左右子树进行交换
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
    void Mirror(TreeNode *pRoot) {
    	if(pRoot == NULL){
    		return;
    	}
    	Trans(pRoot, pRoot->left, pRoot->right);
    }
    void Trans(TreeNode* &proot, TreeNode *pl, TreeNode *pr){
    	if(pl == NULL && pr == NULL){
    		return;
    	}
    	if(pl != NULL){
    		Trans(pl, pl->left, pl->right);
    	}
    	if(pr != NULL){
    		Trans(pr, pr->left, pr->right);
    	}
    	proot->left = pr;
    	proot->right = pl;
    }
};
