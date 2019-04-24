/*
题目：
小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。
输入描述:
输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。
输出描述:
在一行中输出操作n次之后的b序列,以空格分割,行末无空格。
示例1
输入
4
1 2 3 4
输出
4 2 1 3
示例2
输入
5
1 2 3 4 5
输出
5 3 1 2 4

思路：
判断n是奇数还是偶数 假设数值起始位为1
1.若n是奇数，则从后往前输出奇数下标的数值，再从前往后输出偶数下标的数值
2.若n是偶数，则从后往前输出偶数下标的数值，再从前往后输出奇数下标的数值

*/
#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long *a = new long long[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int isOdd = n%2;
    int i;
    for(i = n-1; i>=0; i=i-2){
        cout<<a[i]<<" ";
    }
    if(isOdd==0){
        i = 0;
    }
    else{
        i = 1;
    }
    for(; i<n; i= i+2){
        cout<<a[i];
        if(i == n-1){
            cout<<endl;
        }
        else{
            cout<<" ";
        }
    }
    
    return 0;
}
