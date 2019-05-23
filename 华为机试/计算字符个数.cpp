/*
题目：
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

输入描述:
输入一个有字母和数字以及空格组成的字符串，和一个字符。

输出描述:
输出输入字符串中含有该字符的个数。

示例1
输入
ABCDEF A
输出
1

思路：（简单）
遍历字符串中每个字符，判断各个字符是否与待匹配字符c一致，若一致则个数加一，否则判断当前字符是否为字母，若为字母，判断忽略大小写后，该字符是否与c一致。
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    char c;
    cin>>s>>c;
    int cnt = 0;
    for(int i = 0; i< s.size();i++){
        if(s[i]==c)
            cnt++;
        else{
            if(s[i]>='a'&& s[i]<='z'){
                if(c==s[i]-'a'+'A')
                    cnt++;
            }
            if(s[i]>='A'&& s[i]<='Z'){
                if(c == s[i]-'A'+'a')
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
