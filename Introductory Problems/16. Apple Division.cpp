#include <bits/stdc++.h>
using namespace std;
#define int long long int

void helper(int idx,int n,int arr[],int s1,int s2,int &ans)
{
    if(idx>=n)
    {
        ans = min(ans,abs(s1-s2));
        return;
    }
    helper(idx+1,n,arr,s1+arr[idx],s2,ans);
    helper(idx+1,n,arr,s1,s2+arr[idx],ans);
}

int32_t main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int ans = LONG_MAX,s1=0,s2=0;
    
    helper(0,n,arr,s1,s2,ans);
    
    cout<<ans<<endl;
    return 0;
}
