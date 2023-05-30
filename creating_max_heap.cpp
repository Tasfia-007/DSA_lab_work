/* CREATING MAX HEAP  */

#include<bits/stdc++.h>
using namespace std;

void Insert(vector<int>&v,int data)
{
    v.push_back(data);
        int index = v.size() - 1;
        while (index > 0 && v[index] > v[(index-1)/2])   // use v[index] < v[(index-1)/2] for MIN HEAP
        {
            swap(v[index], v[(index-1)/2]);
            index = (index-1)/2;
        }
}
int main()
{
   vector<int>heap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        Insert(heap,data);
    }
    for(int i=0;i<n;i++)
    cout<<heap[i]<<" ";
}



