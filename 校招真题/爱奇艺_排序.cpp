/*
题目：
牛牛有一个长度为n的整数序列,牛牛想对这个序列进行重排为一个非严格升序序列。牛牛比较懒惰,他想移动尽量少的数就完成重排,请你帮他计算一下他最少需要移动多少个序列中的元素。(当一个元素不在它原来所在的位置,这个元素就是被移动了的)
输入描述:
输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),即序列的长度
第二行n个整数x[i](1 ≤ x[i] ≤ 100),即序列中的每个数
输出描述:
输出一个整数,即最少需要移动的元素个数
示例1
输入
3
3 2 1
输出
2

思路：
定义两个数组存储原始序列，对其中一个数组进行排序。定义cnt记录需要移动的元素，判断两个数组相同下标的数值是否相等，若不相等，则表示该元素需要移位，cnt加一
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *x = new int[n];
    int *tmp = new int[n];
    for(int i = 0; i< n; i++)
    {
        cin>>x[i];
        tmp[i] = x[i];
    }
    sort(tmp,tmp+n);
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(tmp[i]!=x[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
