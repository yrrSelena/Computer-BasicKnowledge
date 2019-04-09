/*
题目：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
思路：
前序遍历：根-左-右
中序遍历：左-根-右
1）前序数组的第一个数为根结点
2）在中序遍历数组中找到根结点所在的位置ind，则在ind之前的都是左子树，ind之后的都是右子树
3）递归遍历，构造得到二叉树
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = pre.size();
        if(len == 0){
            return NULL;
        }
        vector<int> left_pre, right_pre, left_vin, right_vin;
        TreeNode* root = new TreeNode(pre[0]);
        int ind = 0;
        while(vin[ind] != pre[0] && ind < len){
            ind++;
        }
        for(int i = 0; i < ind; i++){
            left_pre.push_back(pre[i + 1]);
            left_vin.push_back(vin[i]);
        }
        for(int i = ind + 1; i< len; i++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        root->left = reConstructBinaryTree(left_pre, left_vin);
        root->right = reConstructBinaryTree(right_pre, right_vin);
        return root;
    }
};
