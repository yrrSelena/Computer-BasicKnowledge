/*
题目：
给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
输入描述:
无序整数数组A[n]
输出描述:
满足条件的最大乘积

示例1:
输入:
4
3 4 1 2
输出:
24

思路：
用5个变量分别记录最小值min1、次小值min2、第三大值max1、第二大值max2、最大值max3
输出结果为 min1*min2*max3 和 max1*max2*max3 中较大的值

*/
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 9999999;
int main(){
    //vector<long long> a;
    int n;
    cin>>n;
    long long data, min1,min2,max1,max2,max3;
    min1 = min2 = INF;
    max1 = max2 = max3 = -INF;
    while(cin>>data){
        //a.push_back(data);
        if(data>=max3){
            max1 = max2;
            max2 = max3;
            max3 = data;
        }
        else if(data>=max2){
            max1 = max2;
            max2 = data;
        }
        else if(data>=max1){
            max1 = data;
        }
        if(data<=min1){
            min2 = min1;
            min1 = data;
        }
        else if(data<=min2){
            min2 = data;
        }
    }
    cout<<max(min1*min2*max3, max1*max2*max3)<<endl;
    return 0;
}
