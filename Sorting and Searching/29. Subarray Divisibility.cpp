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
    
    map<int,int> mp;
    mp[0] = 1;
    int ans = 0;
    int req = 0;
    
    for(int i=0;i<n;i++)
    {
        req = (((req+arr[i])%n)+n)%n;
        
        if(mp.find(req) != mp.end())
        {
            ans += (mp[req]);
        }
        mp[req]++;
    }
    
    cout<<ans<<endl;
    return 0;
}
