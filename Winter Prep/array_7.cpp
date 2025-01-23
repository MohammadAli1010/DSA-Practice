#include <iostream>
using namespace std;

int main ()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[10];
    }
    
    int maxx = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i]> maxx)
        {
            maxx=arr[i];
        }
        
    }
    cout<<"Maximum Number"<<maxx<<endl;
    
}