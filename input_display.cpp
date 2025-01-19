#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the number" << " " << i + 1 << ": ";
        cin >> arr[i];
    }
}