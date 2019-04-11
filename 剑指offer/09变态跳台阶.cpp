/*
题目：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
思路：
n级台阶有2^n种跳法，利用数组存放数据
*/
class Solution {
public:
    int jumpFloorII(int number) {
        vector<long long> a;
        a.push_back(1);
        a.push_back(1);
        a.push_back(2);
        for(int i = 3; i <= number; i++){
            if(i%2 == 1){
                a.push_back(a[(i+1)/2]*a[(i+1)/2]);
            }
            else{
                a.push_back(a[i/2]*a[i/2+1]);
            }
        }
        return a[number];
    }
};
