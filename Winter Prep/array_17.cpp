#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int k;
    
    for (int i = 0; i < 10; i++)
    {
        
        cin>>arr[i];
    }
    cin>>k;
    int last = arr[10];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j<9; i++)
        {
            arr[j] = arr[j+1];

            
        }
        arr[9] = last;


        
    }
    cout<<"Rotated Array";
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
