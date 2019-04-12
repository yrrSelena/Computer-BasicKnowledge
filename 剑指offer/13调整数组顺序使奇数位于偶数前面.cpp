/*
知识点：数组
题目：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
思路：
开辟一个数组存放偶数
顺序遍历数组，若为奇数，则放在原数组前部，若为偶数则存放在新数组中。
遍历完毕后，在原数组的奇数后面将新数组的偶数存入。
注意位运算的优先级较低，应加括号
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i, i_odd = 0;
        int len = array.size();
        vector<int> even;
        for(i = 0; i < len; i++){
            if((array[i]&1) == 0){ //注意位运算的优先级较低
                even.push_back(array[i]);
            }
            else{
                array[i_odd++] = array[i];
            }
        }
        i = 0;
        while(i_odd < len){
            array[i_odd++] = even[i++];
        }
        return;
    }
};
