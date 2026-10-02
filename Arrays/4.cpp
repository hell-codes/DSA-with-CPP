/*
Question_4:
Sort the array in ascending order and then swap every
adjacent pair of elements to form the waveform.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];

    for(int i=0;i<n;i++)
    {
        cin >> array[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i]>array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for(int i=0;i<n-1;i+=2)
    {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
    }
    for(int i=0;i<n;i++)
    {
        cout << array[i];
        if(i<n-1)
            cout << " ";
    }
    return 0;
}
