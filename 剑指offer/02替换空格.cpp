/*
题目：
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
思路：
1）遍历字符串，获得字符串中的空格数
2）计算得到替换后的字符串长度
3）从后往前遍历原字符串，每个字符存储到替换后对应的位置上
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int cnt = 0;
        int rawLen;
        int newLen;
        // 1）统计字符串中的空格数
        for(rawLen =0; str[rawLen] != '\0'; rawLen++){
            if( str[rawLen] == ' '){
                cnt++;  
            }
        }
        // 2）得到替换后字符串的长度
        newLen = rawLen + cnt * 2;
        if(newLen > length){
            return;
        }
        str[newLen]='\0'; // 字符串末尾注意加结束符
        
        // 3）进行字符替换
        for(rawLen = rawLen-1; rawLen>=0; rawLen--){
            if(str[rawLen]==' '){
                str[--newLen] = '0';
                str[--newLen] = '2';
                str[--newLen] = '%';
            }
            else{
                str[--newLen] = str[rawLen];
            }
        }
        
	}
};
