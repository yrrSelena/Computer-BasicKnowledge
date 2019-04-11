/*
题目：
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
思路：
斐波那契数列
假设在2*n的大矩形最左侧竖着放小矩形，则大矩形剩余部分的放法与2*(n-1)的大矩形放法一样（a[n-1]种）
假设在2*n的大矩形最左侧横着放小矩形，则最左下也只能横放一个小矩形，则剩余部分的放法与2*(n-2)的大矩形放法一致（a[n-2]种）
即总放法有 a[n]=a[n-1]+a[n-2]种
*/
class Solution {
public:
    int rectCover(int number) {
        vector<int> a;
        a.push_back(1);
        a.push_back(1);
        for(int i = 2; i <= number; i++)
        {
            a.push_back(a[i-1]+a[i-2]);
        }
        a[0] = 0;
        return a[number];
    }
};
