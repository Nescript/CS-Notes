#include <iostream>

using namespace std;

class DynamicArray
{   
private:
    int* data;
    int size;
public:
    DynamicArray(int s)
    {
        size = s;
        data = new int[size];
    }
    ~DynamicArray()
    {
        delete[] data;
        cout << "Array is free now" << endl;
    }
    void set(int index, int value)
    {
        if (index < size && index >= 0) data[index] = value;
        else cout << "illgel index!" << endl;
    }
    void get(int index)
    {
        if (index < size && index >= 0) cout << data[index] << endl;
        else cout << "illgel index!" << endl;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray array(5);
    array.set(-5, 1);
    array.set(1, 2);
    array.set(2, 3);
    array.set(3, 4);
    array.set(4, 5);
    array.print();
}