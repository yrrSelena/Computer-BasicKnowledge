/*
题目：
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

思路：
层序遍历
利用队列存放每一层的节点，每遍历一层，depth+1
若某个节点的左右孩子都为空，则输出depth
*/
class Solution {
public:
    int run(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            depth++;
            int len = q.size();
            TreeNode* t;
            for(int i = 0; i< len; i++)
            {
                t= q.front();
                q.pop();
                if(t->left == NULL && t->right == NULL){
                    return depth;
                }
                if(t->left != NULL){
                    q.push(t->left);
                }
                if(t->right != NULL){
                    q.push(t->right);
                }
            }
        }
        return depth;
    }
};
