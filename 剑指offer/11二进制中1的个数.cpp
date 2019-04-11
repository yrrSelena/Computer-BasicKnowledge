/*
题目：
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
思路：
正数：补码=原码
负数：补码=原码取反+1（符号位不改变）
0的补码只有一个

对于8位二进制数：
补码可以表示的范围：[-128，127]
0的补码：00000000
-1的补码：11111111
-128的补码：10000000

首先判断n是否为负数，若为负数，则将其取反并加一
利用sizeof得到int的字节数，乘8表示int的位数
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         bool isNeg = false;
         if(n < 0){
             isNeg = true;
             n = -n;
             n = n - 1;
         }
         while(n != 0){
             cnt += n%2;
             n = n/2;
         }
         if(isNeg){
             cnt = sizeof(int)*8 - cnt;
         }
         return cnt;
     }
};
