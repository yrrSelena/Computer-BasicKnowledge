/*
题目：
如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。
输入描述:
输入包括字符串s,s的长度length(1 ≤ length ≤ 50),字符串中只包含'0'和'1'
输出描述:
输出一个整数,表示最长的满足要求的子串长度。
示例1
输入
111101111
输出
3
示例2
输入
00011100
输出
2

思路：
题意是找到最长的连续01串，注意是连续的。
定义一个数组dp存储前i个字符中的最长连续子串，遍历每个字符
1.若s[i]==s[i-1]，则01子串不连续，dp[i]=1
2.否则，01子串连续，dp[i]=dp[i-1]+1
最后，输出数组dp中的最大值。
*/
#include <iostream>
#include <string>
using namespace std;
int dp[55];
int main(){
    string s;
    cin>>s;
    //memset(dp,0,sizeof(dp));
    dp[0] = 1;
    int max_res = 1;
    for(int i = 1; i<s.size(); i++){
        if(s[i]==s[i-1]){
            dp[i] = 1;
        }
        else{
            dp[i] = dp[i-1]+1;
        }
        if(dp[i]>max_res){
            max_res = dp[i];
        }
    }
    cout<<max_res<<endl;
    return 0;
}
