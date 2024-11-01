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
    int l=0,r=0;
    int maxStreak = INT_MIN;
    
    while(r<n)
    {
        if(mp.find(arr[r])==mp.end())
        {
            mp[arr[r]] = r;
        }
        else
        {
            if(mp[arr[r]] >= l)
            {
                l = mp[arr[r]]+1;
            }
            mp[arr[r]]=r;
        }
        maxStreak = max(maxStreak,r-l+1);
        r++;
    }
    cout<<maxStreak<<endl;
}

