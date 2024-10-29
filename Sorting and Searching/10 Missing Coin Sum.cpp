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
    
    int s = 1;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] > s)
        {
            cout<<s<<endl;
            return 0;
        }
        s+=arr[i];
    }
    cout<<s<<endl;
    return 0;
}
