#include<iostream>
using namespace std;
typedef struct BSTNode{
	int val;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode, *BSTree;

//二叉查找
void search(BSTree bst, int key, BSTNode* &pre, BSTNode* &pos){
	BSTNode *p = bst;
	pre = NULL;
	pos = NULL;
	if(p!=NULL && p->left == NULL && p->right == NULL){
		if(p->val == key){
			pos = p;
		}
		return;
	}
	while(p != NULL){
		if(p->val == key){
			pos = p;
			return;
		}
		else{
			pre = p;
			if(p->val < key){
				p = p->right;
			}
			else{
				p = p->left;
			}
		}
	}
	return;
}

//插入节点
void insertBSTNode(BSTree &t, int key){
	BSTNode *p, *pre;
	search(t, key, pre,p);
	if( p != NULL){
		return ;
	}
	else {
		BSTNode* x = new BSTNode;
		x->val = key;
		x->left = NULL;
		x->right = NULL;
		if(t == NULL){
			t=x;
		}
		else{
			if(pre == NULL){
				pre = t;
			}
			if(key > pre->val){
				pre->right = x;
			}
			else{
				pre->left = x;
			}
		}
	}
	return;
}
//创建二叉排序树
void createBSTree(BSTree &t, int * a, int n){
	t = NULL;
	for(int i= 0; i < n; i++){
		insertBSTNode(t,a[i]);
	}
}

//中序遍历
void InOrder(BSTree t){
	if(t !=NULL)
	{
		InOrder(t->left);
		cout<<(t->val)<<" ";
		InOrder(t->right);
	}
}
//删除节点
void deleteBSTNode(BSTree &t, int key){
	BSTNode *p, *pre;
	search(t,key,pre,p);
	if(p == NULL)
	{
		cout<<"no such node values "<<key<<endl;
	}
	else{
		//cout<<(pre->val)<<endl;
		if(p->right == NULL && p->left == NULL){
			if(pre == NULL)
			{
				t = NULL;
			}
			else 
			{
				if(pre->left != NULL && pre->left->val == p->val){
					pre->left = NULL;
				}
				else if(pre->right != NULL && pre->right->val == p->val){
					pre->right = NULL;
				}
			}
			return;
		}
		BSTNode *p1, *pp1;
		if(p->right!=NULL){
			p1 = p->right;
			pp1 = p;
			if(p1->left == NULL){
				pp1->right = NULL;
			}
			else{
				while(p1->left!=NULL){
					pp1 = p1;
					p1 = p1->left;
				}
				pp1->left = NULL;
			}
			p->val = p1->val;
			return;
		}
		
		if(p->left !=NULL){
			//cout<<(p->left->val)<<endl;
			p1 = p->left;
			pp1 = p;
			if(p1->right == NULL){
				pp1->left = NULL;
			}
			else{
				while(p1->right!=NULL){
					pp1 = p1;
					p1 = p1->right;
				}
				pp1->right = NULL;
			}
			p->val = p1->val;
		}
		
		
	}
}

int main(){
	int a[5]={3,1,2,5,4};//{4,3,2,5,1};//
	BSTree t;
	cout<<"Create BSTree"<<endl;
	createBSTree(t, a, 5);
	cout<<"In order display:";
	InOrder(t);
	cout<<endl;
	cout<<"Delete BSTNode"<<endl;
	deleteBSTNode(t,2);
	cout<<"In order display:";
	InOrder(t);
	cout<<endl;
	return 0;
}
