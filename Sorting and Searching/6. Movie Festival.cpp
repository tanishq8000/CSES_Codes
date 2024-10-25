#include <bits/stdc++.h>
using namespace std;
#define int long long int

static bool com(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
int32_t main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end(),com);
    int ans = 1;
    
    pair<int,int> p = v[0];
    
    for(int i=1;i<n;i++)
    {
        if(v[i].first >= p.second)
        {
            ans++;
            p = v[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
