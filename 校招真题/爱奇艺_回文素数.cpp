/*
题目：
如果一个整数只能被1和自己整除,就称这个数是素数。
如果一个数正着反着都是一样,就称为这个数是回文数。例如:6, 66, 606, 6666
如果一个数字既是素数也是回文数,就称这个数是回文素数
牛牛现在给定一个区间[L, R],希望你能求出在这个区间内有多少个回文素数。
输入描述:
输入包括一行,一行中有两个整数(1 ≤ L ≤ R ≤ 1000)
输出描述:
输出一个整数,表示区间内回文素数个数。
示例1
输入
100 150
输出
2

思路：
既要判断是否为回文以及是否为素数
回文：由于整数范围限制在1000以内，因此可以定义一个数组存放各个位的数值，判断顺次判断数组左侧与数组右侧的值是否一致
【注意】1不是素数
*/
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int a){
    bool res = true;
    int i;
    if(a==1)
        return false;
    for(i = 2; i <= sqrt(a); i++){
        if(a%i == 0){
            res = false;
            break;
        }
    }
    return res;
}
bool isHuiwen(int a){
    bool res = true;
    int weishu = 1;
    int tmp = a;
    int *arr = new int[5];
    while(tmp/10!=0){
        arr[weishu] = tmp%10;
        tmp /= 10;
        weishu++;
    }
    arr[weishu] = tmp;
    int i = 1, j = weishu;
    while(i<j){
        if(arr[i]==arr[j]){
            i++;j--;
        }
        else{
            res = false;
            break;
        }
    }
    return res;
}
int main(){
    int L,R;
    cin>>L>>R;
    
    int cnt = 0;
    for(int i = L; i<=R; i++){
        if(isHuiwen(i)&&isPrime(i)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}
