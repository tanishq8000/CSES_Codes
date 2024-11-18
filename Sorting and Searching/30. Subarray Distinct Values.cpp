#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int l=0,r=0,ans=0;
    unordered_map<int,int> mp;
    
    while(r<n)
    {
        mp[arr[r]]++;
        
        while(mp.size() > k)
        {
            mp[arr[l]]==1 ? mp.erase(arr[l]) : mp[arr[l]]--;
            l++;
        }
        
        ans += (r-l+1);
        r++;
    }
    
    cout<<ans<<endl;
    return 0;
}
