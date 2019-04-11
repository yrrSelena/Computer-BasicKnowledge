/*
题目：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
思路：
a^n = a^(n/2) * a^(n/2)， n为偶数
a^n = a^((n-1)/2) * a^((n-1)/2) * a， n为奇数
将exponent用二进制数表示
注意考虑exponent为负数和0的情况
*/
class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1.0;
        if(exponent < 0){
            exponent = -exponent;
            base = 1.0/base;
        }
        double tmp = base;
        /*
        for(int i = 0; i < exponent; i++){
            res = res * base;
        }
        */
        while(exponent!=0){
            if(exponent%2 == 1){
                res = res * tmp;
            }
            tmp = tmp * tmp;
            exponent /= 2;
        }
        return res;
    }
};
