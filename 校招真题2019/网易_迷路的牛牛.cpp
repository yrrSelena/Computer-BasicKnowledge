/*
https://www.nowcoder.com/questionTerminal/fc72d3493d7e4be883e931d507352a4a?f=discussion
题目描述
牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。
输出描述:
输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。
示例1
输入
复制
3
LRR
输出
复制
E

思路：
一个L会和一个R抵消，只需用一个变量iloc模拟更改当前位置即可
遇到L，iloc加一，遇到R时，iloc减1
此外，每4个L或每4个R会形成一个循环，回到初始方向，因此对iloc进行除4取余，防止iloc数值过大
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        string s;
        cin>>s;
        int i=0;
        int iloc = 0;
        while(i<n){
            if(s[i]=='L')
                iloc = (iloc+1)%4;
            else
                iloc = (iloc+4-1)%4; //注意要加4取余，保证iloc的取值在0-3之间。
            i++;
        }
        char loc[4] = {'N','W','S','E'};
        cout<<loc[iloc]<<endl;
    }
}
