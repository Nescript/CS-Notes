#include<iostream>
using namespace std;
struct Complex
{
    float Realpart;
    float Imagepart;
};
void Create(Complex &C,float x, float y)
{
    C.Realpart=x;
    C.Imagepart=y;
}
//在C语言中没有引用的写法，所以是用指针来传递
//书本写作 &Complex C
float GetReal(Complex C)
{
    return C.Realpart;
}
float GetImag(Complex C)
{
    return C.Imagepart;
}
Complex Add(Complex C1,Complex C2)
{
    Complex sum;
    sum.Realpart=C1.Realpart+C2.Realpart;
    sum.Imagepart=C1.Imagepart+C2.Imagepart;
    return sum;
}
Complex Sub(Complex C1,Complex C2)
{
    Complex difference;
    difference.Realpart=C1.Realpart-C2.Realpart;
    difference.Imagepart=C1.Imagepart-C2.Imagepart;
    return difference;
}
int main()
{
    float Real,Image;
    cin>>Real>>Image;
    Complex A;
    Create(A,Real,Image);
    cin>>Real>>Image;
    Complex B;
    Create(B,Real,Image);
    Complex dif=Sub(A,B);
    Complex summ=Add(A,B);
    cout<<GetReal(dif)<<"+"<<GetImag(dif)<<"i"<<endl;
    cout<<GetReal(summ)<<"+"<<GetImag(summ)<<"i"<<endl;
    cout<<GetReal(A)<<"+"<<GetImag(A)<<"i"<<endl;
    cout<<GetReal(B)<<"+"<<GetImag(B)<<"i"<<endl;
    return 0;
}