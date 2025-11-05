#include <iostream>
using namespace std;
class Shape
{
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void display()
    {
        cout << name << endl;
    } 
    virtual ~Shape() {};
};
class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle(double wid, double h) : Shape("Rectangle"), width(wid), height(h) {}
    double getArea() const override
    {
        return width * height;
    } 
    double getPerimeter() const override
    {
        return (width + height) * 2;   
    }
    void display() override
    {
        Shape::display();
        cout << "width is " << width << endl;
        cout << "height is " << height << endl;
    }
};
class Circle : public Shape
{
private:
    double radius;
    static const double PI;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    double getArea() const override
    {
        return PI * radius * radius;
    }
    double getPerimeter() const override
    {
        return radius * 2 * PI;
    }
    void display() override
    {
        Shape::display();
        cout << "radius is " << radius <<endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int v) : Rectangle(v, v) {}
};
double const Circle::PI = 3.14;
int main() {
    // 测试1：不能实例化抽象类
    // Shape s("test");  // 应该编译错误
    
    // 测试2：创建对象并调用方法
    Rectangle rect(5, 10);
    rect.display();
    cout << endl;
    
    Circle circle(7);
    circle.display();
    cout << endl;
    
    Square square(6);
    square.display();
    cout << endl;
    
    // 测试3：多态
    Shape* shapes[3];
    shapes[0] = &rect;
    shapes[1] = &circle;
    shapes[2] = &square;
    
    cout << "=== Polymorphism Test ===" << endl;
    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << endl;
    }
    
    return 0;
}
