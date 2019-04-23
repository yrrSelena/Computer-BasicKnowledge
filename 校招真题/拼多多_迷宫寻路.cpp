/*
题目：
假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。请设计一个算法，帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
输入描述:
迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N
后面的M行是矩阵的数据，每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
输出描述:
路径的长度，是一个整数
示例1
输入
5 5
02111
01a0A
01003
01001
01111
输出
7

思路：
广度优先搜索 状态压缩
题目中限定最多10把钥匙，因此用10位二进制数表示钥匙的状态，即共有1024种状态
用isVisit[M][N][1024]数组记录在某种钥匙状态下，G[x][y]是否被访问过
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX=105;
//上下左右
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char G[MAX][MAX];
int M,N;
int x_st,y_st;
int isVisit[MAX][MAX][1500];
struct node{
    int x,y,k,step;
    node():x(0),y(0),k(0),step(0){};
    node(int x, int y, int k, int step):x(x),y(y),k(k),step(step){};
};
int bfs(){
    queue<node> q;
    q.push(node(x_st,y_st,0,0));
    while(q.empty()==false){
        node t = q.front();
        q.pop();
        if(G[t.x][t.y]=='3')
            return t.step;
        for(int i = 0; i < 4; i++){
            node tmp;
            tmp.x = t.x+dx[i];
            tmp.y = t.y+dy[i];
            tmp.k = t.k;
            if(tmp.x<0 || tmp.x>=M || tmp.y<0 || tmp.y>=N ||G[tmp.x][tmp.y]=='0'){
                continue;
            }
            if(G[tmp.x][tmp.y]>='a'&&G[tmp.x][tmp.y]<='z'){
                tmp.k = tmp.k|(1<<(G[tmp.x][tmp.y]-'a'));
            }
            if(G[tmp.x][tmp.y]>='A'&&G[tmp.x][tmp.y]<='Z'){
                int p= tmp.k&(1<<(G[tmp.x][tmp.y]-'A'));
                if(p == 0)
                    continue;
            }
            if(isVisit[tmp.x][tmp.y][tmp.k]==0){
                isVisit[tmp.x][tmp.y][tmp.k]=1;
                tmp.step=t.step+1;
                q.push(tmp);
            }
        }
    }
    return 0;
}
int main(){
    cin>>M>>N;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            cin>>G[i][j];
            if(G[i][j] == '2'){
                x_st = i;
                y_st = j;
            }
        }
    }
    memset(isVisit,0,sizeof(isVisit));
    cout<<bfs()<<endl;
    return 0;
}
