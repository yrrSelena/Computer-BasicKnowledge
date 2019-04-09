class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = (int)array.size(); //行数
        int m = (int)array[0].size(); //列数
        int i = 0, j = m-1;  //从矩阵的右上角开始
        while(i < n && j>=0 ){
            if(array[i][j] < target){ 
                i++;
            }
            else if(array[i][j] > target){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};
