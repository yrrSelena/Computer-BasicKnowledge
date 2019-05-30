/*
题目：
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。

输入描述:
输入一个正浮点数值

输出描述:
输出该数值的近似整数值

示例1
输入
复制
5.5
输出
复制
6

思路：
接收两个数据：分别是long long和string类型的，通过判断string中第二个字符是否大于'5'，进行四舍五入
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    long long a;
    string s;
    cin>>a>>s;
    if(s[0]=='.'){
        if(s[1]>='5')
            a++;
    }
    cout<<a<<endl;
    return 0;
}
