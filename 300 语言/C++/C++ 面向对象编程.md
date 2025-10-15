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
我们可以将void方法改为返回类名&（引用类型）来实现链式调用，即：
```cpp
class book
{
public:
	book& saysth()
	{
		std::cout << "Hi" << std::endl;
		return *this; 
		// 返回的是this指针指向的类，注意*在这里解引用了，所以是操作地址位置的类
	}
}

int main()
{
	book a;
	a.saysth().saysth()
	// 执行顺序是左到右
}
```
## 2.3 常量成员
const 成员变量可以被列表初始化
const 成员函数只能调用const成员函数
mutable 关键字表明该变量可以在const 成员函数中被改变（例如访问次数什么的）
## 2.4 静态成员
静态成员非常特立独行，无论创建多少个类的对象，都只有一个静态成员的副本。
静态成员的初始化只在类外进行，如果没有初始化语句，则会被初始化为0
静态成员函数也类似，首先只能访问类的静态成员数据，就算没有类的对象也能访问。
```cpp
#include <iostream>
#include <memory>
using namespace std;
class Myclass
{
public:
	static int class_cnt;
	static void getClassCnt();
	Myclass() {Myclass::class_cnt++;}
	~Myclass() {Myclass::class_cnt--;}
};
int Myclass::class_cnt = 0;
void Myclass::getClassCnt()
{
	cout << Myclass::class_cnt << endl;
}
int main()
{
	Myclass::getClassCnt(); // output 0
	unique_ptr<Myclass> i = make_unique<Myclass>();
	Myclass::getClassCnt(); // output 1
	return 0;
}
```
# 第三部分：继承
## 3.1 继承基础
继承是一种“is-a”句式：子类是一个基类
例如 dog is a animal
`class dog : public animal`
这里狗就是派生类（子类），animal就是基类
继承方式：public、protected、private
我们一般用public来继承，可以简单的理解这里的关键字决定了基类的public和protected对象在子类里访问权限的变化：
	对public继承，那么基类的public在子类也是public, protected在子类也是protected
	对protected/private继承，那么基类的保护和私有对象就变成子类的protected/private对象
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
`class a : public c, public d, public k`

**虚继承**是C++中为了解决多继承（尤其是菱形继承）问题而引入的一种机制。它的主要目的是在多继承中避免数据冗余和二义性问题。
`class a : virtual public c`
在多继承中，如果一个基类被多个派生类继承，而这些派生类又被另一个类继承时，基类的成员会在最终派生类中出现多份拷贝。这种情况会导致存储空间浪费以及访问成员时的歧义。虚继承通过确保基类的成员在最终派生类中只保留一份，从而解决了这些问题。
# 第四部分：多态
## 4.1 函数重载
函数重载的概念
重载的规则
运算符重载
## 4.2 虚函数和动态绑定
virtual 关键字表明该函数是虚函数，可以被重载
虚函数表（vtable）是具体实现的细节，姑且不讨论
在虚函数的基础上添加 = 0 标记就是纯虚函数，包含纯虚函数的父类强制要求子类给出实现。
包含纯虚函数的类就是抽象类，抽象类不能实例化
## 4.3 多态的应用
其实要点就是我们可以用基类的指针管理派生类对象
==动态绑定 vs 静态绑定== 
如果没有使用 virtual、override这些关键字，那就是静态绑定的。
动态绑定实现了我用基类的指针管理派生类对象。
好比Animal都会eat、speak，但Dog和Cat具体eat和speak都不同。那么可以在基类Animal中声明纯虚函数eat、speak来要求子类给出实现。
最后在运行时，编译器会确定具体使用函数的哪一个实现。

虚析构函数是必要的，对于我们采用基类指针管理派生类对象的需求，虚析构函数能确保正确调用派生类的析构函数

override关键字类似于一个检查。派生类的方法一旦使用override关键字，就要求其继承的父类有一个与之对应的需要重载的虚函数，若没有则无法通过编译
final关键字就是说这个函数不允许再重载了

# 第五部分：运算符重载
在这之前可以补充函数重载：在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。
就像之前学构造函数的时候，一个类可以有多个包含不同形参的构造函数。
## 5.1 运算符重载基础
```cpp
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;
class Point
{
private:
	int x{ 0 };
	int y{ 0 };
public:
	Point(int x, int y) : x(x), y(y) {}
	Point operator+(const Point& other)
	{
		return Point(this->x + other.x, this->y + other.y);
	}
	Point operator-(const Point& other)
	{
		return Point(this->x - other.x, this->y - other.y);
	}
	void output()
	{
		cout << "x is " << x << " and y is " << y << endl;
	}
};
int main()
{
	unique_ptr<Point> a = make_unique<Point>(15, 2);
	unique_ptr<Point> b = make_unique<Point>(2, 3);
	Point c = *a - *b;
	c.output();
	c = c.operator-(*b);
	c.output();
}
```
通过运算符重载，我们可以让类的运算变得符合直觉，譬如建立向量类，那么就可以重载加法减法，以及大于小于来模拟实际向量的运算。
## 5.2 友元函数
friend 权限很高，可以访问私有和保护成员
也许可以用来实现日志功能
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

