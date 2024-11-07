#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({{a,b},i});
    }
    
    sort(v.begin(),v.end());
    
    
    set<pair<int,int>> s;
    int room = 0;
    
    vector<int> ans(n);
    
    for(int i=0;i<n;i++)
    {
        int arr = v[i].first.first;
        int dep = v[i].first.second;
        int idx = v[i].second;
        
        if(s.empty())
        {
            room++;
            s.insert({dep,room});
            ans[idx] = room;
        }
        else
        {
            int val = (*s.begin()).first;
            int r = (*s.begin()).second;
            if(val<arr)
            {
                s.erase(s.begin());
                s.insert({dep,r});
                ans[idx]=r;
            }
            else
            {
                room++;
                s.insert({dep,room});
                ans[idx] = room;
            }
        }
    }
    
    cout<<room<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
