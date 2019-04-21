/*
题目：
有两个用字符串表示的非常大的大整数,算出他们的乘积，也是用字符串表示。不能用系统自带的大整数类型。
输入描述:
空格分隔的两个字符串，代表输入的两个大整数
输出描述:
输入的乘积，用字符串表示
示例1
输入
72106547548473106236 982161082972751393
输出
70820244829634538040848656466105986748

思路：
模拟，按位计算，考虑进位
注意：
样例需要考虑一正一负、两个负数、数据为0等情况
*/
#include<iostream>
#include<string>
using namespace std;
string multiply(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();
    int n = n1 + n2;
    bool isNeg = false;
    if(s1[0]=='-' && s2[0]=='-')
    {
    	isNeg = false;
    }
    else if(s1[0]=='-' || s2[0]=='-'){
        isNeg = true;
    }
    string s(n,'0'); //字符串自动填充n个0
    s[n]='\0';
    for(int i = n1-1; i >=0 && s1[i]!='-'; i--){
        for(int j = n2 - 1; j >= 0 && s2[j]!='-'; j--){
            int c = (s1[i]-'0')*(s2[j]-'0');
            int offset = 0;
            while(c){
                c = s[i + j + 1 - offset] -'0' + c;
                s[i + j + 1 - offset] = c%10 +'0';
                c = c/10;
                offset++;
            }
        }
    }
    //处理负号以及数据开头有多余0的情况
    int st, i;
    if(isNeg){
        s[0] = '-';
        st = 1;
    }
    else{
        st = 0;
    }
    i = 0;
    while(st+i<n && s[st+i]=='0'){
        i++;
    }
    if(st + i == n){
        i--;
    }
    if(i>0)
        s.erase(st,i); //删除st起始的i 个字符
    return s;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<multiply(s1,s2)<<endl;
    return 0;
}
