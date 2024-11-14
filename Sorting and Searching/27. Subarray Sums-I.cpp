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
    
    unordered_map<int,int> mp;
    mp[0] = 1;
    int ans = 0;
    int currSum = 0;
    
    for(int i=0;i<n;i++)
    {
        currSum += arr[i];
        int req = currSum-x;
        
        if(mp.find(req) != mp.end())
        {
            ans += (mp[req]);
        }
        mp[currSum]++;
    }
    
    cout<<ans<<endl;
    return 0;
}
