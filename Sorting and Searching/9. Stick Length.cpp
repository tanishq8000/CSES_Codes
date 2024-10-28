#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    int ans = 0;
    
    for(int i=0;i<n;i++)
    {
        ans += abs(arr[n/2]-arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
