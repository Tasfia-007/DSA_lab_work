/*HEAPIFYING AN ARRAY*/

#include<bits/stdc++.h>
using namespace std;

void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[],int i)
{

         int index = i ;
        while (index > 0 && arr[index] > arr[(index-1)/2])   // use v[index] < v[(index-1)/2] for MIN HEAP
        {
            Swap(&arr[index], &arr[(index-1)/2]);
            index = (index-1)/2;
        
        }
}
int main()
{
  
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    Heapify(arr,i);
    
     for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
}

