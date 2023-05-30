#include<bits/stdc++.h>
using namespace std;

void Swap(int *a , int *b)
{
   *a = *a ^ *b;
   *b = *a ^ *b;
   *a = *a ^ *b;
}

void Bubble_Sort(int arr[] , int n)
{
    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            Swap(&arr[j] , &arr[j+1]);
        }
    }
}

int main()
{
    int n ;
    cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
    cin >> arr[i] ;
    Bubble_Sort(arr,n) ;

    for(int i = 0 ; i < n ; i++)
    cout << arr[i] << " " ;
}
