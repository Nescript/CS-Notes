知识大纲
# 第一部分：基础概念
## 1.1 面向对象编程简介
面向对象是一种编程范式，将数据和操作数据的方式封装在一起，形成“对象”
OOP的三大特性：
	封装：将数据和方法包装在类中，隐藏内部实现细节
	继承：子类可以集成父类的属性和方法
	多态：同一个接口可以有不同的实现
## 1.2 类的基础
类的定义和声明
```cpp
class Myclass
{
private:
	int a;
	// private 里的成员变量（aka属性）只有自己可以访问，子类无法访问
protected:
	int b;
	// protected 里的成员变量子类和自己可以访问，类外无法访问
public:
	Myclass(int k) : a(k) {} // 带参数的构造函数初始化列表
	~Myclass() {} // 析构函数
	// public 里的方法、属性全局都可以访问
};

int main()
{
	Myclass one(11);
	// 类的实例化，这里创建了一个Myclass对象one
}
```
## 1.3 构造函数和析构函数
### 构造函数
这里展示了构造函数的相关细节：
- 构造函数具有与类相同的名称
- 构造函数没有返回值
- 一般来说构造函数声明为public，但private和protect也是可以的
此处参考微软教程的代码：
```cpp
class Box {
public:
    // Default constructor
    Box() {}

    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {}

    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width{ 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};
```
注意到这里面出现了 explicit 关键字，这是用于修饰只有一个参数的类构造函数，表明该构造函数是显式的，而非隐式的，这会阻止一些操作，比如：
```cpp
Box i = 10;
Box i = ‘c’;
// 如果没有explicit关键字，这两条语句都能执行，编译器会进行隐式的转换：
// Box i = 10; 此时等效于 Box i(10);
// Box i = 'c'; 则是将 c 的ascii码作为参数构造Box
// 当参数多于 2 个时，编译器就不会进行这样的操作了，所以不需要加关键字。
// 不过还有一种情况是参数多于2个，但除了第一个参数之外的参数都带有默认值，如
Box(int age, int size = 0) // size 默认值为 0
// 此时编译器也是会进行隐式转换的
```
explicit与implicit（隐式）相对，后者是类构造函数的默认情况下的声明。

如果没有给出构造函数，编译器会创建默认的构造函数。此时需要确保类属性都具有默认值，如：
```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int Volume() {return m_width * m_height * m_length;}
private:
    int m_width { 0 }; // 后面的 0 就是默认值
    int m_height { 0 };
    int m_length { 0 };
};

int main() {
    Box box1; // Invoke compiler-generated constructor
    cout << "box1.Volume: " << box1.Volume() << endl; // Outputs 0
}
```

### 析构函数
在对象超出范围或者通过delete显式销毁对象时，会自动调用析构函数
析构的顺序是后构造的先析构

一般来说此部分涉及 new  和 delete 的知识，待补充。
# 第二部分：封装
## 2.1 数据隐藏
我们通过private控制符避免在类外更改类中的成员属性
我们一般提供set方法在类外设置private属性，用get方法在类外读取private属性。
例如：
```cpp
#include <iostream>
using namespace std;

class Myclass
{
private:
	int info;
	string str;
public:
	int getInfo() const // get 方法一般都打上 const 表明不会改变对象的属性
	{
		return info;
	}
	string getStr() const
	{
		return str;
	}
	void setInfo(int a)
	{
		info = a;
	}
	void setStr(const string &a) // 注意这一句，我们通过引用方式传参避免拷贝
								 // 同时 const 确保我们不会更改 a 的值
								 // 这种方法一般用在复杂的对象上，如果是int那种基础类型
								 // 就像 setInfo 里面那样拷贝值即可
	{
		str = a;
	}
}
```
## 2.2 this 指针
this 指针指向调用成员函数的对象本身
我们可以通过this指针区分成员变量（属性）和参数，例如：
```cpp
book(string name) // book类的构造函数
{
	this->name = name;
}
//不过其实成员初始化列表不用考虑那么多：
book(string name) : name(name) {}
```

this 指针的使用场景
返回 `*this`实现链式调用

## 2.3 常量成员
const 成员变量
const 成员函数
mutable 关键字
## 2.4 静态成员
静态成员变量
静态成员函数
静态成员的初始化
# 第三部分：继承
## 3.1 继承基础
继承的概念和语法
基类和派生类
继承方式：public、protected、private
访问权限的变化
## 3.2 构造和析构顺序
派生类的构造过程
派生类的析构过程
调用基类构造函数
## 3.3 继承中的访问控制
派生类对基类成员的访问
友元函数和继承
protected 的作用
## 3.4 多重继承
多重继承的语法
菱形继承问题
虚继承
# 第四部分：多态
## 4.1 函数重载
函数重载的概念
重载的规则
运算符重载
## 4.2 虚函数和动态绑定
虚函数的概念
virtual 关键字
虚函数表（vtable）
纯虚函数
抽象类
## 4.3 多态的应用
基类指针和派生类对象
==动态绑定 vs 静态绑定== 
虚析构函数的必要性
override 和 final 关键字（C++11）
# 第五部分：运算符重载
## 5.1 运算符重载基础
为什么需要运算符重载
可重载的运算符
不可重载的运算符
## 5.2 常见运算符重载
算术运算符：`+、-、*、/`
比较运算符：、!=、<、>
赋值运算符：=
输入输出运算符：<<、>>
下标运算符：
函数调用运算符：()
## 5.3 友元函数
友元函数的概念
友元类
何时使用友元
# 第六部分：高级特性
## 6.1 模板类
类模板的定义
类模板的实例化
模板特化
## 6.2 异常处理
try-catch-throw 机制
异常类的设计
构造函数中的异常
## 6.3 智能指针（C++11）
unique_ptr
shared_ptr
weak_ptr
RAII 原则
## 6.4 移动语义（C++11）
右值引用
移动构造函数
移动赋值运算符
std::move

