/*
题目：
对于任意两个正整数x和k,我们定义repeat(x, k)为将x重复写k次形成的数,例如repeat(1234, 3) = 123412341234,repeat(20,2) = 2020.
牛牛现在给出4个整数x1, k1, x2, k2, 其中v1 = (x1, k1), v2 = (x2, k2),请你来比较v1和v2的大小。
输入描述:
输入包括一行,一行中有4个正整数x1, k1, x2, k2(1 ≤ x1,x2 ≤ 10^9, 1 ≤ k1,k2 ≤ 50),以空格分割
输出描述:
如果v1小于v2输出"Less",v1等于v2输出"Equal",v1大于v2输出"Greater".
示例1
输入
1010 3 101010 2
输出
Equal

思路：
将数据转化为字符串进行比较
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string x1,x2;
    int k1, k2;
    cin>>x1>>k1>>x2>>k2;
    string large1 = x1, large2 = x2;
    for(int i = 1; i<k1; i++){
        large1 += x1;
    }
    for(int i = 1; i<k2; i++){
        large2 += x2;
    }
    int flag = 0;
    if(large1 != large2){
        int len1 = large1.size();
        int len2 = large2.size();
        if(len1>len2)
            flag = 1;//Greater;
        else if(len1 < len2)
            flag = -1;
        else{
            if(large1>large2)
                flag = 1;
            else
                flag = -1;
        }
    }
    switch(flag){
        case -1:
            cout<<"Less"<<endl;break;
        case 0:
            cout<<"Equal"<<endl;break;
        case 1:
            cout<<"Greater"<<endl;break;
    }
    return 0;
}
