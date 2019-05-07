/*
题目：
牛牛举办了一场数字游戏,有n个玩家参加这个游戏,游戏开始每个玩家选定一个数,然后将这个数写在纸上(十进制数,无前缀零),然后接下来对于每一个数字将其数位按照非递减顺序排列,得到新的数,新数的前缀零将被忽略。得到最大数字的玩家赢得这个游戏。
输入描述:
输入包括两行,第一行包括一个整数n(1 ≤ n ≤ 50),即玩家的人数
第二行n个整数x[i](0 ≤ x[i] ≤ 100000),即每个玩家写下的整数。
输出描述:
输出一个整数,表示赢得游戏的那个玩家获得的最大数字是多少。
示例1
输入
3
9638 8210 331
输出
3689

思路：
将每个玩家的数按照字符串的形式存储
采用sort对每个玩家的字符串进行从小到大排序，并删除为0的字符
比较字符串的大小：若当前字符串与目前最大数的字符串长度相等，则比较两个字符串的大小；若当前字符串的长度比最大数的字符串更长，则更新最大数的字符串。
（需要掌握string的相关函数）
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string *x = new string[n];
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }
    for(int i = 0; i<n; i++){
        sort(x[i].begin(),x[i].end());//对字符串进行排序
        x[i].erase(remove(x[i].begin(),x[i].end(),'0'),x[i].end()); //删除字符串前面多余的‘0’
    }
    string max_num = x[0];
    int max_len = max_num.size();
    for(int i = 1; i<n; i++){
        if(x[i].size()>max_len){
            max_num = x[i];
            max_len = x[i].size(); //更新最大数字符串的长度
        }
        else if(x[i].size()==max_len && x[i]>max_num){
            max_num = x[i];
            max_len = x[i].size();
        }
    }
    cout<<max_num<<endl;
    return 0;
}
