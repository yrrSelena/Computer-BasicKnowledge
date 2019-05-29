/*
题目：
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
输入描述:
输入一个十六进制的数值字符串。
输出描述:
输出该数值的十进制字符串。
示例1
输入
复制
0xA
输出
复制
10

思路：
以字符串的形式读取16进制数，用long long存储十进制结果（疑问：当数据较大时，如何实现？）
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int len;
    long long res;
    while(cin>>s){
        len = s.size();
        res = 0;
        for(int i = 0; i<len; i++){
            if(s[i]>='0'&&s[i]<='9'){
                res = res*16+s[i]-'0';
            }
            else if(s[i]>='A'&&s[i]<='F'){
                res = res*16 + s[i]-'A'+10;
            }
            else if(s[i]>='a'&&s[i]<='f'){
                res = res*16 + s[i]-'a'+10;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
