#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool products(int arr[],int n,int t,int sec)
{
    int pro = 0;
    for(int i=0;i<n;i++)
    {
        pro += (sec/arr[i]);
        if(pro>=t)
        {
            return true;
        }
    }
    return false;
}

int32_t main() {
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int l=1,r=(*max_element(arr,arr+n))*t;
    //cout<<r<<endl;
    
    int ans=0;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(products(arr,n,t,mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
