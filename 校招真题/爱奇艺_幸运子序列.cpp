/*
题目：
牛牛得到一个长度为n的整数序列V,牛牛定义一段连续子序列的幸运值为这段子序列中最大值和次大值的异或值(次大值是严格的次大)。牛牛现在需要求出序列V的所有连续子序列中幸运值最大是多少。请你帮帮牛牛吧。
输入描述:
第一行一个整数n,即序列的长度。(2<= n <= 100000)
第二行n个数，依次表示这个序列每个数值V[i], (1 ≤ V[i] ≤ 10^8)且保证V[1]到V[n]中至少存在不同的两个值.
输出描述:
输出一个整数,即最大的幸运值
示例1
输入
5
5 2 1 4 3
输出
7
示例2
输入
5
9 8 3 5 7
输出
15

思路：
将数组中的一个元素a[i]看作次大值，分别向左和向右扫描得到第一个比a[i]大的数，作为最大值maxl和maxr，计算最大值与a[i]的异或，并取最大结果。
扫描数组中所有元素，求得最终的幸运数。
【注】要得到第一个比a[i]大的数，若扫描得到多个比a[i]大的数，则a[i]就不是次大值了
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long *a = new long long[n];
    long long maxl,maxr,resV = -1;
    for(int i = 0; i< n;i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        maxl = a[i];
        for(int j = i-1; j>=0; j--){
            if(a[j]>maxl)
            {
                maxl = a[j];
                break;
            }
        }
        maxr = a[i];
        for(int j = i+1; j<n;j++){
            if(a[j]>maxr){
                maxr = a[j];
                break;
            }
        }
        if(maxr!=a[i]&& maxl!=a[i])
            resV = max(resV,max(a[i]^maxl,a[i]^maxr));
        else if(maxl!=a[i])
            resV = max(resV,a[i]^maxl);
        else if(maxr!=a[i])
            resV = max(resV,a[i]^maxr);
    }
    cout<<resV<<endl;
    return 0;
}
