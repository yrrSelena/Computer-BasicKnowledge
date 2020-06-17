
##### const
- const对象默认为文件的局部变量，只存在于该文件中，不能被其他文件访问
- 可以通过指定const变量为extern，实现在整个程序中访问const对象
- 非const变量默认为extern

##### 声明 VS 定义
- 定义用于为变量分配存储空间，还可以为变量指定初始值
- 声明不是定义，也不分配存储空间，可通过extern关键字声明变量名而不定义它
- 只有定义才分配存储空间
- 变量可以声明多次但只能定义一次

```cpp

extern int a; //声明

extern int b = 1; //定义
int c = 1;
int d; //定义

```
##### 头文件
- 头文件用于声明而不是定义
- 头文件包含在多个源文件中，因此不应该含有变量或函数的定义
- 例外：头文件可以定义类、值在编译时就已知的const对象、inline函数。这些实体可在多个源文件中定义，只要保证每个源文件中的定义相同即可

#### 标准库类型
##### string
- string的+操作的左右操作数必须至少有一个是string类型的
- string类型的初始化将两个字符串字面值相加是非法的
- string::size_type为string的下标类型，类似于unsigned int
- toupper(c),islower(c)等函数可用于string中单个字符的操作

```cpp
string s1 = "aa";
string s2 = "aa" + "bb"; //非法
string s3 = s1 + "aa" +"bb"; //合法，s3进行初始化的时候，s1+"aa"先返回一个新的string对象，然后这个新对象与字面值"bb"连接
string s4 = "aa" + "bb" + s1; //非法
```
##### vector
- 必须是已存在的元素才能用下标进行索引
```cpp
vector<T> v(n,val); //v包含n个值为val的元素

vector<int>::size_type //下标类型

//完整版
//安全泛型编程，由于vector是可以动态增长的，因此更倾向于每次循环中测试size的当前值，而不是在进入循环前存储size值的副本
for(vector<int>::size_type i=0; i!=nums.size(); i++) 
	nums[i]=0;

//精简版，auto自动识别类型
for(auto &num:nums) 
	nums[i]=0

//迭代器iterator版
for(vector<int>::iterator iter=nums.begin(); iter!=nums.end(); ++iter)
	*iter = 0; //解引用操作符（*操作符）访问迭代器所指的元素
```

- const_iterator对象 vs const的iterator对象
```cpp
vector<int>::const_iterator //迭代器所指的元素不能修改
const vector<int>::iterator //该迭代器不能指向别的元素
```
- 任何改变vector长度的操作都会使已存在的迭代器失效
