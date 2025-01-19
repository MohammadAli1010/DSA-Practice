#include <iostream>
using namespace std;
int main()
{
    int arr[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    int index = -1;
    int findd;
    cout << "Enter the number you want to find: ";
    cin >> findd;

    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == findd)
        {
            index = i;
            break;
        }
    }
    if (findd != -1)
    {
        cout << "The index is: " << index;
    }
    else
    {
        cout << "The number is not found in the array.";
    }
    return 0;
}