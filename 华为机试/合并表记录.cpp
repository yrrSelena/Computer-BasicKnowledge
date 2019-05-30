/*
题目：
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述:
先输入键值对的个数
然后输入成对的index和value值，以空格隔开
输出描述:
输出合并后的键值对（多行）
示例1
输入
复制
4
0 1
0 2
1 2
3 4
输出
复制
0 3
1 2
3 4

思路：
利用STL中的Map进行索引与值的匹配 详见https://www.cnblogs.com/hushaojun/p/6012206.html
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int cmp(const pair<int, int> &x, const pair<int,int> &y){
    return x.first<y.first;
}
void sortByKey(map<int,int>& m, vector<pair<int,int>> &res){
    for(map<int, int>::iterator curr = m.begin(); curr != m.end(); curr++){
        res.push_back(make_pair(curr->first,curr->second));
    }
    sort(res.begin(),res.end(),cmp);
    return;
}
int main(){
    int n;
    cin>>n;
    map<int,int> m;
    map<int,int>::iterator it;
    int index;
    int value;
    for(int i = 0; i<n; i++)
    {
        cin>>index>>value;
        it = m.find(index);
        if(it!=m.end()){
            it->second += value;
        }
        else{
            m.insert(make_pair(index,value));
        }
    }
    vector<pair<int,int>> res;
    sortByKey(m,res);
    for(int i = 0; i<res.size(); i++){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}
