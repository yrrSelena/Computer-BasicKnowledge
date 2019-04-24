/*
题目：
小易有一些彩色的砖块。每种颜色由一个大写字母表示。各个颜色砖块看起来都完全一样。现在有一个给定的字符串s,s中每个字符代表小易的某个砖块的颜色。小易想把他所有的砖块排成一行。如果最多存在一对不同颜色的相邻砖块,那么这行砖块就很漂亮的。请你帮助小易计算有多少种方式将他所有砖块排成漂亮的一行。(如果两种方式所对应的砖块颜色序列是相同的,那么认为这两种方式是一样的。)
例如: s = "ABAB",那么小易有六种排列的结果:
"AABB","ABAB","ABBA","BAAB","BABA","BBAA"
其中只有"AABB"和"BBAA"满足最多只有一对不同颜色的相邻砖块。
输入描述:
输入包括一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),s中的每一个字符都为一个大写字母(A到Z)。
输出描述:
输出一个整数,表示小易可以有多少种方式。
示例1
输入
ABAB
输出
2
示例2:
输入
XYZ
输出
0
示例3：
输入
AAAA
输出：
1

思路：
题目很简单，本质就是判断字符串中不同字符的个数
1.若有3个及以上不同的字符，则不存在最多只有一对不同颜色的相邻砖块，输出0；
2.若有2个不同的字符，则输出2
3.若只有一种字符，则输出1
由于字符被限制在A-Z之间，因此可定义一个空间为26的bool数组，用于判断字符是否出现过
注意：
看清题意
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool block[30];
int main(){
    string s;
    cin>>s;
    int n_block = 0;
    int cnt;
    memset(block,false,sizeof(block));
    for(int i  = 0; i< s.size(); i++){
        int c = s[i]-'A';
        if(block[c]==false){
            n_block++;
        }
        block[c]=true;
    }
    if(n_block == 2){
        cnt = 2;
    }
    else if(n_block == 1){
        cnt = 1;
    }
    else{
        cnt = 0;
    }
    cout<<cnt<<endl;
    return 0;
}
