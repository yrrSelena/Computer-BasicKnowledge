/*
题目：
牛牛手中有三根木棍,长度分别是a,b,c。牛牛可以把任一一根木棍长度削短,牛牛的目标是让这三根木棍构成一个三角形,并且牛牛还希望这个三角形的周长越大越好。
输入描述:
输入包括一行,一行中有正整数a, b, c(1 ≤ a, b, c ≤ 100), 以空格分割
输出描述:
输出一个整数,表示能拼凑出的周长最大的三角形。
示例1
输入
1 2 3
输出
5

思路：
创建一个大顶堆存放三边的长度
循环判断三边是否满足1）三角形两边之和大于第三边<每次只需判断最大边是否小于剩余两边之和>、2）两边之差小于第三边
若满足，则退出循环并输出周长
否则，最大边减1
*/
#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> a;
    int tmp;
    for(int i = 0; i< 3; i++){
        cin>>tmp;
        a.push(tmp);
    }
    int max1, max2, max3;
    while(1)
    {
        max1 = a.top();
        a.pop();
        max2 = a.top();
        a.pop();
        max3 = a.top();
        if(max1<max2+max3 && max1-max2 <max3 && max1-max3 <max2)
            break;
        max1--;
        a.push(max2);
        a.push(max1);
    }
    cout<<max1+max2+max3<<endl;
    return 0;
}
