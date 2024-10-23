#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n),arr2(m);
    multiset<int> p;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
        p.insert(arr1[i]);
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    
    vector<int> ans(m,0);
    for(int i=0;i<m;i++)
    {
        auto ub = p.upper_bound(arr2[i]);
        
        if(ub == p.begin())
        {
            ans[i] = -1;
        }
        else
        {
            ub--;
            ans[i] = *(ub);
            p.erase(ub);
        }
    }
    
    for(auto x:ans)
    {
        cout<<x<<endl;
    }
    
    return 0;
}
