/*
题目：
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
思路：
用数组存储斐波那契数列，而不是递归求解。
*/
class Solution {
public:
    int Fibonacci(int n) {
        int* a = new int[40];
        a[0] = 0;
        a[1] = 1;
        for( int i = 2; i < 40; i++){
            a[i] = a[i-1] + a[i-2];
        }
        return a[n];
    }
};
