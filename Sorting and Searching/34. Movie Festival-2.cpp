#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());
    
    multiset<int> ms;
    int ans = 0;
    
    for(int i=0;i<k;i++)
    {
        ms.insert(v[i].second);
    }
    
    for(int i=k;i<n;i++)
    {
        auto mn = ms.begin();
        auto mx = ms.rbegin();
        
        if(v[i].first >= (*mn))
        {
            ans++;
            ms.erase(mn);
            ms.insert(v[i].second);
        }
        else if(v[i].second < (*mx))
        {
            ms.erase(ms.find(*mx));
            ms.insert(v[i].second);
        }
    }
    
    cout<<ans+ms.size()<<endl;
    return 0;
}
