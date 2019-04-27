/*
题目：
有一种有趣的字符串价值计算方式:统计字符串中每种字符出现的次数,然后求所有字符次数的平方和作为字符串的价值
例如: 字符串"abacaba",里面包括4个'a',2个'b',1个'c',于是这个字符串的价值为4 * 4 + 2 * 2 + 1 * 1 = 21
牛牛有一个字符串s,并且允许你从s中移除最多k个字符,你的目标是让得到的字符串的价值最小。
输入描述:
输入包括两行,第一行一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),其中只包含小写字母('a'-'z')。
第二行包含一个整数k(0 ≤ k ≤ length),即允许移除的字符个数。
输出描述:
输出一个整数,表示得到的最小价值
示例1
输入
aba
1
输出
2
示例2
输入
wersrsresesrsesrawsdsw
11
输出
23

思路：
不能用贪心算法求解
利用大顶堆存放字符出现的次数，由于可以删除k个字符，每次删除出现次数最多的一个字符，若该字符还存在，则放回大顶堆，否则不用放回。
直至k=0 或 字符被删除完
*/
#include<iostream>
#include<string>
#include<cstring>
#include <queue>
using namespace std;

int main(){
    string s;
    int k;
    cin>>s>>k;
    int *num = new int[26];
    int i;
    for(i = 0; i<26; i++){
        num[i] = 0;
    }
    for(i = 0; i<s.size(); i++){
        num[s[i]-'a']++; 
    }
    priority_queue<int> q;
    for(i = 0; i<26; i++){
        if(num[i]>0)
            q.push(num[i]);
    }
    int res = 0;
    while(k>0 && !q.empty()){
        int max1 = q.top();
        q.pop();
        max1--;
        if(max1>0)
            q.push(max1);
        k--;
    }
    while(!q.empty()){
        int tmp = q.top();
        res = res + tmp*tmp;
        q.pop();
    }
    cout<<res<<endl;
    return 0;
}
