/*
难度：一般

题目：
牛牛有一些排成一行的正方形。每个正方形已经被染成红色或者绿色。牛牛现在可以选择任意一个正方形然后用这两种颜色的任意一种进行染色,这个正方形的颜色将会被覆盖。牛牛的目标是在完成染色之后,每个红色R都比每个绿色G距离最左侧近。牛牛想知道他最少需要涂染几个正方形。
如样例所示: s = RGRGR
我们涂染之后变成RRRGG满足要求了,涂染的个数为2,没有比这个更好的涂染方案。
输入描述:
输入包括一个字符串s,字符串s长度length(1 ≤ length ≤ 50),其中只包括'R'或者'G',分别表示红色和绿色。
输出描述:
输出一个整数,表示牛牛最少需要涂染的正方形数量
示例1
输入
RGRGR
输出
2

思路：
目标是将字符串转变为前一部分均为R，后一部分均为G的形式。
额外定义两个数组G[]和R[]，分别记录当前字符之前‘G’的个数和当前字符之后‘R’的个数
当前字符前的'G'的个数+当前字符后的'R'的个数，即为以当前字符为划分点，需要修改的字符数。
最小的G[i]+R[i]，即为最小值。
*/
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len = s.size();
    int *G = new int[len];//当前字符前面G的个数
    int *R = new int[len];//当前字符后面R的个数
    G[0] = 0;
    R[len-1] = 0;
    for(int i =1; i<len; i++){
        if(s[i-1]=='G')
        {
            G[i] = G[i-1] + 1;
        }
        else{
            G[i] = G[i-1];
        }
    }
    for(int i = len-2; i>=0; i--){
        if(s[i+1]=='R'){
            R[i] = R[i+1] + 1;
        }
        else{
            R[i] = R[i+1];
        }
    }
    int n_min = len;
    for(int i = 0; i< len; i++){
        if(G[i] + R[i]<n_min){
            n_min = G[i] + R[i];
        }
    }
    cout<<n_min<<endl;
    return 0;
}
