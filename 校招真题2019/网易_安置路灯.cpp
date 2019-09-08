/*
题目描述
小Q正在给一条长度为n的道路设计路灯安置方案。
为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。
输入描述:
输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
第二行一个字符串s表示道路的构造,只包含'.'和'X'。
输出描述:
对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。
示例1
输入
2
3
.X.
11
...XX....XX
输出
1
3

思路：
判断字符s[i]，
若字符为'.'，则路灯数目加1，下标i往后移3个位置
若字符为'X'，下标往后移1个位置
*/
/*复杂版-自己想复杂了orz*/
#include<iostream>
using namespace std;
int main(){
    int c;
    cin>>c;
    while(c--){
        int n;
        string s;
        cin>>n>>s;
        int led = -2;
        int res = 0;
        for(int i = 0; i<n; i++){
            if(i-led<2){
                continue;
            }
            if(s[i]=='X'){
                continue;
            }
            else{
                if(i+2<n){
                    if(s[i+1]=='X' && s[i+2]=='X'){
                        led = i;
                        i = i+2;
                    }
                    else{
                        led = i+1;
                        i = i+2;
                    }
                    res++;
                }
                else{
                    res++;
                    break;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
/*简易版*/
#include<iostream>
using namespace std;
int main(){
    int c;
    cin>>c;
    while(c--){
        int n;
        string s;
        cin>>n>>s;
        int i=0;
        int res = 0;
        while(i < n){
            if(s[i]=='.'){
                i += 3;
                res++;
            }
            else
                i += 1;
        }
        cout<<res<<endl;
    }
    return 0;
}
