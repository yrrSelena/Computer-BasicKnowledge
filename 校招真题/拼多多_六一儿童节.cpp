/*
题目：
六一儿童节，老师带了很多好吃的巧克力到幼儿园。每块巧克力j的重量为w[j]，对于每个小朋友i，当他分到的巧克力大小达到h[i] (即w[j]>=h[i])，他才会上去表演节目。老师的目标是将巧克力分发给孩子们，使得最多的小孩上台表演。可以保证每个w[i]> 0且不能将多块巧克力分给一个孩子或将一块分给多个孩子。
输入描述:
第一行：n，表示h数组元素个数
第二行：n个h数组元素
第三行：m，表示w数组元素个数
第四行：m个w数组元素
输出描述:
上台表演学生人数

示例1
输入
3 
2 2 3
2
3 1 
输出
1

思路：
贪心算法
首先对数组h和w进行排序，用下标i,j分别记录当前知道的h和w的最大值
若当前最大的w[j]不能满足h[i]，说明j之前的任何一块巧克力都不能满足第i个小孩，则i--
若w[j]>=h[i]，则将第j块巧克力分配给第i个小孩
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    int *h = new int[n];
    for(int i = 0; i< n ;i++)
    {
        cin>>h[i];
    }
    sort(h, h+n);
    cin>>m;
    int *w = new int[m];
    for(int i = 0; i< m ;i++)
    {
        cin>>w[i];
    }
    sort(w, w+m);
    int cnt = 0;
    int i = n-1, j = m-1;
    while(i>=0 && j>=0){
        if(w[j]>=h[i]){
            cnt++;
            j--; i--;
        }
        while(w[j]<h[i]){
            i--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
