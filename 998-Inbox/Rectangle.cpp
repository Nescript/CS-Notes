#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double length;
        double width;
    public:
        Rectangle (double len, double wid) : length(len), width(wid) {}
        double area() {return length * width;}
        double perimeter() {return (length + width) * 2;}
};
int main()
{
    double wid,len;
    cin >> wid >> len;
    Rectangle usrRec(len, wid);
    /*Rectangle defRec();*/
    cout << usrRec.area() << " " << usrRec.perimeter() << endl; 
}