/*
题目：
有三只球队，每只球队编号分别为球队1，球队2，球队3，这三只球队一共需要进行 n 场比赛。现在已经踢完了k场比赛，每场比赛不能打平，踢赢一场比赛得一分，输了不得分不减分。已知球队1和球队2的比分相差d1分，球队2和球队3的比分相差d2分，每场比赛可以任意选择两只队伍进行。求如果打完最后的 (n-k) 场比赛，有没有可能三只球队的分数打平。  
输入描述:
第一行包含一个数字 t (1 <= t <= 10)
接下来的t行每行包括四个数字 n, k, d1, d2(1 <= n <= 10^12; 0 <= k <= n, 0 <= d1, d2 <= k)
输出描述:
每行的比分数据，最终三只球队若能够打平，则输出“yes”，否则输出“no”
示例1
输入
复制
2
3 3 0 0
3 3 3 3
输出
复制
yes
no
说明
case1: 球队1和球队2 差0分，球队2 和球队3也差0分，所以可能的赛得分是三只球队各得1分
case2: 球队1和球队2差3分，球队2和球队3差3分，所以可能的得分是 球队1得0分，球队2得3分, 球队3 得0分，比赛已经全部结束因此最终不能打平。

思路：
分4种情况分别讨论。(比较复杂)
详见https://www.nowcoder.com/profile/704205296/codeBookDetail?submissionId=42486880
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k,d1,d2;
        cin>>n>>k>>d1>>d2;
        int flag = true;
        if(n%3!=0){
            cout<<"no"<<endl;
            continue;
        }
        else{
            long long tmp, remain;
            tmp = k-d1-d1-d2;
            if(tmp>=0 && tmp%3 ==0){
                remain = n-k -(d1+d2+d2);
                if(remain>=0 && remain%3==0){
                    cout<<"yes"<<endl;continue;
                }
            }
            tmp = k-d1-d1+d2;
            if(tmp>=0 && tmp%3==0){
                remain = n-k - (d1+d2);
                if(remain>=0 && remain%3==0){
                    cout<<"yes"<<endl;continue;
                }
            }
            tmp = k+d1+d2+d2;
            if(tmp>=0 && tmp%3==0){
                remain = n-k - (d1+d1+d2);
                if(remain>=0 && remain%3==0){
                    cout<<"yes"<<endl;continue;
                }
            }
            tmp = k+d1+d1-d2;
            if(tmp>=0 && tmp%3==0){
                remain = n-k - max(d1,d2)-abs(d1-d2);
                if(remain>=0 && remain%3==0){
                    cout<<"yes"<<endl;continue;
                }
            }
            cout<<"no"<<endl;
        }
    }
    return 0;
}
