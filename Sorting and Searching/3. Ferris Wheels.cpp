#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,x;
    cin>>n>>x;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    int i=0,j=n-1,cnt=0;
    
    while(i<=j)
    {
        if(arr[i]+arr[j] <= x)
        {
            cnt++;
            i++;
            j--;
        }
        else
        {
            cnt++;
            j--;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}
