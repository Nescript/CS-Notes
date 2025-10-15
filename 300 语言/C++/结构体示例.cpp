#include <iostream>

#define MAXSIZE 100
using namespace std;

typedef struct 
{
    int data[MAXSIZE];
    // 等价于 int data[100];
    int length;
} Sqlist;
//上面的语句定义了一个名为Sqlist的结构体
//typedef是type define的缩写，表明Sqlist被定义一个类型名
//这样就可以用 Sqlist 来定义说明新的变量了

struct Sqlist2 
{
    int data[MAXSIZE];
    int length;
};

int main()
{
    Sqlist list_1;
    //我定义了一个名为list_1的Sqlist类型的结构体
    struct Sqlist2 list_2;
    //这里定义了一个名为list_2的Sqlist2类型的结构体
}