/*
题目：
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； 
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。 
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组

示例1
输入
复制
abc
123456789
输出
复制
abc00000
12345678
90000000

思路：
首先判断字符串长度是否为8的倍数，若不是，则在字符串后填充若干个0
然后8位8位输出字符串。
【注】s.substr(i,n)表示截取从第i个字符开始，后面n个字符。
*/
#include<iostream>
#include<string>
using namespace std;

const int LEN = 8;
void outString(string s){
    int len = s.size();
    int mod = len%LEN;
    if(mod>0){
        for (int j = 0; j<LEN-mod; j++){
            s = s+'0';
        }
    }
    len = s.size();
    int i = 0;
    while(i<len){
        cout<<s.substr(i,LEN)<<endl;
        i += LEN;
    }
    return;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    outString(s1);
    outString(s2);
    return 0;
}
