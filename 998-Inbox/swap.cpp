#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    MyClass() {cout << "now we got an new class" << endl;}
    void doSomething() {
        std::cout << "Doing something" << std::endl;
    }
    ~MyClass() {cout << "say good bye" << endl;}
};

int main() {
    shared_ptr<MyClass> myPtr1(new MyClass);
    { 
        unique_ptr<MyClass> myPtr2(new MyClass);
        myPtr2->doSomething();
    }

    myPtr1->doSomething(); // 使用 myPtr1 调用成员函数
     // 使用 myPtr2 调用成员函数

    // 当 myPtr1 和 myPtr2 都被销毁时，MyClass 对象的内存才会被释放
    return 0;
}