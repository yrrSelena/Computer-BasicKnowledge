## 题目
[面试题57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9

输出：[[2,3,4],[4,5]]

示例 2：

输入：target = 15

输出：[[1,2,3,4,5],[4,5,6],[7,8]]

 

限制：

  1 <= target <= 10^5


## 方法
### 思路（双指针）
- 采用两个指针l和r表示当前枚举到的以l为起点，r为终点的区间，sum表示[l,r]的区间和，利用求和公式$sum=\frac{(l+r)*(r-l+1)}{2}$计算。
- 设置初值：l=1,r=2
1. 若sum==target 且满足合法区间（l<r），可将区间序列存入res数组。由于以l为起点的合法解最多有一个，因此需要枚举下一个起点，将l右移。
2. 若sum<target，说明当指针r应向右移来增大sum。
3. 若sum>target，说明以l为起点不存在一个r使得sum=target，因此需要枚举下一个起点，将l右移。
- 循环以上操作，直至l>target/2，此时，不可能有满足条件的解，因此退出循环。


### 复杂度分析
- 时间复杂度O(target)：两个指针均单调不减，且最多移动target/2次。
- 空间复杂度O(1)：采用常数的空间存放变量

### 代码
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l=1, r=2;
        int sum = 3;
        vector<vector<int>> res;
        while(l<=target/2){
            if(sum==target && l<r){
                vector<int> tmp(r-l+1);
                iota(tmp.begin(),tmp.end(),l);
                res.push_back(tmp);
                sum-=l;
                l++;
            }
            else if(sum<target){
                r++;
                sum+=r;
            }
            else{
                sum-=l;
                l++;
            }
        }
        return res;
    }
};
```

### 测评
执行用时 :4 ms, 在所有 C++ 提交中击败了79.87% 的用户

内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户
