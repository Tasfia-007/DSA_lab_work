#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int x,int n) {
    int low=0;
    int high=n-1;

    while (low<=high) {
        int mid = (low+high)>>1;
        
        if (arr[mid] == x)
            return mid;
        
        if (arr[mid] < x)
            low= mid + 1;
        else
            high= mid - 1;
    }

    return -1; 
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k;
    cin>>k;
    sort(a,a+n);
    cout<<binarySearch(a,k,n)<<'\n';
}