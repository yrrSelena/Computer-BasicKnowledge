/*
题目：
小易非常喜欢拥有以下性质的数列:
1、数列的长度为n
2、数列中的每个数都在1到k之间(包括1和k)
3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
例如,当n = 4, k = 7
那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。
输入描述:
输入包括两个整数n和k(1 ≤ n ≤ 10, 1 ≤ k ≤ 10^5)
输出描述:
输出一个整数,即满足要求的数列个数,因为答案可能很大,输出对1,000,000,007取模的结果。
示例1
输入
2 2
输出
3

思路：
动态规划
dp[i][j]表示前i个数字，以j结尾的数列中，小易喜欢的数列个数
原本是要求满足条件的数列个数，但是满足条件的数列明显比不满足条件的数列多
因此通过下式进行转换 总数列个数-不满足条件的数列个数=满足条件的数列个数
dp[i][j]=sum(dp[i-1][1,2,...,k]) + sum(dp[i-1][t]<t是j的倍数，且t!=j>)
注意：这里sum(dp[i-1][1,2,...,k])对于每个j都是一样的，所以不需要每次都求。
最终的结果就是求sum(dp[n][1,2,…,k])
注意二维数组的定义
*/
#include<iostream>
#include<cstring>
using namespace std;
const long long MOD=1000000007;
int main(){
    int n,k;
    cin>>n>>k;
    int **dp = new int*[n+1];
    for(int i = 0;i<=n; i++){
        dp[i] = new int[k+1];
    }
    //memset(dp,0,sizeof(dp));
    for(int i = 1; i<=k; i++){
        dp[1][i] = 1;
    }
    int sum, minus;
    for(int i = 2; i<=n; i++){
        sum = 0;
        for(int j = 1; j<=k; j++){
            sum += dp[i-1][j];
            sum %= MOD;
        }
        for(int j = 1; j<=k; j++){
            minus = 0;
            for(int t = j + j; t<=k; t= t+j){
                minus += dp[i-1][t];
                minus %= MOD;
            }
            dp[i][j] = (sum-minus + MOD)%MOD;
        }
    }
    int res = 0;
    for(int i = 1; i<=k;i++){
        res += dp[n][i];
        res %=MOD;
    }
    cout<<res<<endl;
    return 0;
}
