#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[5] = {1, 3, 5, 2, 4};
    int maxPosition = max_element(arr ,arr + 5) - arr; 
    int minPosition = min_element(arr, arr + 5) - arr;
    int temp = arr[maxPosition];
    arr[maxPosition] = arr[minPosition];
    arr[minPosition] = temp;
    for (auto a : arr)
    {
        cout << a << " ";
    }
}