/*
题目：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
思路：
方法一：一次遍历数组，找到数组中的最小值，时间复杂度为O(n)（不能达到要求）
方法二：利用旋转数组的特性，通过二分查找，寻找最小值，时间复杂度为O(logn)
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        int min_num = rotateArray[0];
        while(left <= right){
            int mid = (left + right) / 2;
            if(rotateArray[mid] > min_num){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                min_num = rotateArray[mid];
            }
        }
        return min_num;
    }
};
