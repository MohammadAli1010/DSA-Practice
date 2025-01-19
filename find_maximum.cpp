#include <iostream>
using namespace std;
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int maxx = INT16_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    cout << "The largest number is : " << maxx;

    return 0;
}