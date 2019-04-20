/*
题目：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

思路：
设置4个变量left,right,up,down确定边界
向右遍历一定存在
向下遍历需要满足up<down
向左遍历需要满足left<right并且up<down
向上遍历需要满足left<right并且up+1<down
注意：考虑1X1,1X2,2X1等矩阵
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
    	int n_row = matrix.size();
    	int n_col = matrix[0].size();
    	//cout<<n_row<<n_col<<endl;
    	int left = 0, right = n_col-1, up = 0, down = n_row - 1;
    	while(left<=right && up<=down){
    		for(int i = left; i <= right; i++){
    			res.push_back(matrix[up][i]);
    		}
    		if(up < down)
    		{
    			for(int j = up + 1; j <=down; j++){
	    			res.push_back(matrix[j][right]);
	    		}
    		}
    		if(up < down && left < right)
    		{
    			for(int i = right -1; i >= left; i--){
	    			res.push_back(matrix[down][i]);
	    		}
    		}
    		if(up+1 < down && left < right)
    		{
    			for(int j = down - 1; j > up; j--){
	    			res.push_back(matrix[j][left]);
	    		}
    		}
    		left++;right--;up++;down--;
    	}
    	return res;
    
    }
};
