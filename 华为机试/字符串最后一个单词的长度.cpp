/*
题目：
计算字符串最后一个单词的长度，单词以空格隔开。 
输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

示例1
输入
hello world
输出
5

思路：（题目非常简单）
利用cin以空格为间隔读取字符串的特点，循环读取字符串，直至最后一个字符串，输出单词长度。
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int len;
    while(cin>>s){
        len = s.size();
    }
    cout<<len<<endl;
    return 0;
}
