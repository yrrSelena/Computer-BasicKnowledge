### 第二章 变量与基本类型

#### 基本内置类型

bool, char, int, short, long等算数类型，void特殊类型

- 【注】切勿混用带符号类型和无符号类型。带符号数会自动转换成无符号数


#### 变量定义

- 默认初始化：
  - 定义时没有指定初始化值会被默认初始化（全局变量：int等算数类型默认为0，string默认为""，）
  - 函数体内部的内置类型变量不会被初始化
- 赋值 vs 初始化：
  - 赋值 = 擦除对象的当前值 + 用新值代替
  - **初始化** = 创建变量 + 赋予初始值 （对象在创建时获得了一个特定的值）
- 定义时必须初始化：const，引用，


#### 声明 VS 定义

- 声明：使得名字为程序所知
- 定义：负责创建与名字关联的实体。用于为变量分配存储空间，还可以为变量指定初始值
- 声明不是定义，也不分配存储空间，可通过extern关键字声明变量名而不定义它，用来说明变量定义在其他地方 
- 只有定义才分配存储空间
- 变量可以声明多次但只能定义一次

```cpp
extern int a; //声明

extern int b = 1; //定义
int c = 1;
int d; //定义

```


#### const

- const对象默认为文件的局部变量，只存在于该文件中，不能被其他文件访问
- 可以通过指定const变量为extern，实现在整个程序中访问const对象

```cpp
//在f1.cpp文件中
extern const int i=1; //定义并初始化了一个常量，该常量能够被其他文件访问（若想在多文件之间共享const对象，必须在变量的定义之前添加extern）

//在f2.cpp文件中
extern const int i; //对，与f1.cpp中定义的i是同一个
extern const int i=2;//错，常量不可被再次赋值

```

- 非const变量默认为extern
- 必须被初始化，且不能改变

```cpp
const int i = get_size(); //运行时初始化
const int j = 42; //编译时初始化
```

- 顶层const：指针本身是个常量
- 底层const：指针指向的对象是个常量



##### constexpr和常量表达式

- 常量表达式：值不会改变，且在**编译**过程就能得到计算结果的表达式

```cpp
const int a=20; //字面值属于常量表达式
const int b = a+1; //是常量表达式
const int c = get_size();//不是常量表达式，虽然c是常量，但其具体值直到运行时才能获得
```

- constexpr：让编译器验证变量的值是否为一个常量表达式

```cpp
constexpr int a = 20;
constexpr int b = a+1;
constexpr int c = get_size(); //只有当get_size()是一个constexpr函数时，才是一条真正的声明语句
```

- 字面值类型（算数类型、引用、指针）都能定义成constexpr，而类、IO库、string类型等非字面值类型则不能
- constexpr指针的初始值必须是nullptr或0或存储于某个固定地址的对象

#### 引用 vs 指针

引用：一个对象的别名，本身不是一个对象，必须初始化

- 同：两者都是对内存的间接访问
- 异：
  - 引用：“绑定”内存中的某个对象；指针：“指向”内存中的某个对象
  - 指针是一个对象，运行赋值拷贝，可以指向几个不同的对象；引用不是对象，不能重新绑定到另一个对象上
  - 指针可以不初始化，但引用必须初始化

#### 头文件

- 头文件用于声明而不是定义
- 头文件包含在多个源文件中，因此不应该含有变量或函数的定义
- 例外：头文件可以定义类、值在编译时就已知的const对象、inline函数。这些实体可在多个源文件中定义，只要保证每个源文件中的定义相同即可

- 预处理器：确保头文件多次包含时仍能安全工作
- 当预处理器看到`#include`标记时，会用指定的头文件内容代替`#include`
- 预处理器变量有两种状态：已定义、未定义
- 头文件保护符#ifndef，#endif，#define

### 第三章 字符串、向量和数组

#### string

##### 定义和初始化

- 直接初始化：通过括号给对象赋值，直接调用与实参匹配的构造函数
- 拷贝初始化：使用=将一个已有的对象拷贝到正在创建的对象，总是调用拷贝构造函数（首先使用指定构造函数创建一个临时对象，然后用拷贝构造函数将该临时对象复制到正在创建的对象）
  [详细](https://blog.csdn.net/ljianhui/article/details/9245661?tdsourcetag=s_pctim_aiomsg)

```cpp
string s1;
string s2(s1);//直接初始化，但调用的是拷贝构造函数
string s3("hello");//直接初始化，调用构造函数
string s4="hello";//拷贝初始化，先调用构造函数创建临时对象，后调用拷贝构造函数把值赋给s4
string s5=string();//拷贝初始化，先调用默认构造函数产生一个临时对象，后调用拷贝构造函数把值赋给s5
string s6(n,'c'); //直接初始化，把s4初始化为由连续n个字符'c'组成的串
string s7=string(10,'c');//拷贝初始化 <=> string temp(10,'c'); string s7 = temp;
```

##### string对象上的操作

- 使用getline读取一整行

```cpp
int main()
{
	string line;
	while(getline(cin,line))
		cout<<line<<endl;
	return 0;
}
```

- string::size_type为string的下标类型，是一个无符号类型的值，类似于unsigned int

```cpp
auto len = str.size(); //len的类型是string::size_type
```

- string的+操作的左右操作数必须至少有一个是string类型的
- string类型的初始化将两个字符串字面值相加是非法的

```cpp
string s1 = "aa";
string s2 = "aa" + "bb"; //非法
string s3 = s1 + "aa" +"bb"; //合法，s3进行初始化的时候，s1+"aa"先返回一个新的string对象，然后这个新对象与字面值"bb"连接
string s4 = "aa" + "bb" + s1; //非法
```


##### 处理string对象中的字符

- 用于string中单个字符操作的相关函数：`isalnum(c)` （c是否为字母或数字）,`isalpha(c)`, `isdigit(c)`, `islower(c)`, `toupper(c)`等
- 遍历字符串

```cpp
for(auto c:str) //由编译器决定变量c的类型，每次迭代str的下一个字符被拷贝给c
	cout<<c<<endl;
```

#### vector

`#include<vector>` `using std::vector`

- vector是一个容器，也是一个类模板
- vector是模板而非类型，由vector生成的类型必须包含vector中元素的类型，如`vector<int> `（`vector<int>`是一个类型）

##### 定义和初始化

```cpp
vector<int> v1; //默认初始化，v1不包含任何元素
vector<int> v2(v1); //等价于 vector<int> v2=v1;
//注意区分花括号和括号
//括号：构造vector对象
//花括号：列表初始化vector对象
vector<int> v3(n); //包含n个元素，且元素值均为0的vector对象
vector<int> v4{n}; //包含1个元素，且元素值为n的vector对象 （列表初始化）
vector<int> v4(n,val); //包含n个值为val的动态数组
vector<string> v5{"hello","world"};//列表初始化：对vector对象的元素赋初值，用花括号对vector中每个元素进行初始化
vector<vector<int>> b;//二维数组
```



- 必须是已存在的元素才能用下标进行索引

```cpp
vector<T> v(n,val); //v包含n个值为val的元素

vector<int>::size_type //下标类型

//完整版
//安全泛型编程，由于vector是可以动态增长的，因此更倾向于每次循环中测试size的当前值，而不是在进入循环前存储size值的副本
for(vector<int>::size_type i=0; i!=nums.size(); i++) 
	nums[i]=0;

//精简版，采用范围for循环，auto自动识别类型
//在范围for循环中，不能改变其所遍历序列的大小
for(auto &num:nums) //变量num为一个引用，因此可以通过num对nums元素赋值
	num =0  

//迭代器iterator版
for(vector<int>::iterator iter=nums.begin(); iter!=nums.end(); ++iter)
	*iter = 0; //解引用操作符（*操作符）访问迭代器所指的元素
```



####  迭代器

##### 使用

- iter.begin()指向容器的第一个元素
- iter.end()指向容器尾元素的下一个元素（尾后迭代器）
- 当容器为空时，iter.begin()，iter.end()返回的都是尾后迭代器
- 使用解引用符`*`访问迭代器指向的元素
- const_iterator：只能读取容器内元素，而不能改变它

- const_iterator对象 vs const的iterator对象

```cpp
vector<int>::const_iterator //迭代器所指的元素不能修改，只能读元素
const vector<int>::iterator //该迭代器不能指向别的元素
```

- 箭头运算符：解引用+成员访问  `it->mem`等价于`(*it).mem`

- 任何改变vector长度的操作都会使已存在的迭代器失效

  【注】凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素

##### 运算

- 标准容器迭代器的运算符

`*iter`返回迭代器iter所指的元素的引用；`iter->mem`；`++iter`；`--iter`；`iter==iter1`；`iter!=iter1`

- vector和string的迭代器支持的运算符

`iter+n`; `iter-n`; `iter+=n`; `iter-=n`; `iter1-iter2`; `<`; `<=`;`>`; `>=`

迭代器相减表示两个迭代器之间的距离（距离可正可负，是difference_type的带符号整数类型）

```cpp
auto beg = text.begin(), end = text.end();
auto mid = beg+(end-beg)/2;   //【注】此处不能写 mid = （beg+end)/2; 
```

#### 数组



### 第六章 函数

- 形参和实参的个数和类型必须完全匹配

#### 局部对象

- 局部变量：形参和函数体内部定义的变量。其对函数而言是局部的，对函数外部是隐藏的
- 自动对象：只存在于块执行期间的对象。块执行结束后，自动对象的值就变成了未定义。（内置类型的未初始化局部变量将产生未定义的值）
- 局部静态对象（static）：生命周期贯穿函数调用及之后的时间，直到程序终止才被销毁。若内置类型的局部静态变量没有显式初始化，则被默认初始化为0





### 第七章 类

- 类的基本思想是**数据抽象**和**封装**
- 数据抽象是一种依赖于**接口**和**实现**分离的编程技术
- 封装：实现了类的接口和实现的分离。封装后，类的用户只能使用接口而无法访问实现部分

#### 类成员

- 必须在类内声明，不能在其他地方增加成员
- 成员可以是数据，函数，类型别名

#### 类的构造函数

- 通过一个或几个特殊的成员函数控制对象的初始化过程
- 
