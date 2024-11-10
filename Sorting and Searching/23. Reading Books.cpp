#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int32_t main() {
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    
    sort(arr,arr+n);
    
    int remSum = sum - arr[n-1];
    
    if(remSum >= arr[n-1])
    {
        cout<<arr[n-1]+remSum;
    }
    else
    {
        cout<<2*arr[n-1]<<endl;
    }
    return 0;
}
