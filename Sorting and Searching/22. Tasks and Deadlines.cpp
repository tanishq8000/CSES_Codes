#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int32_t main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());
    
    int currTime = 0;
    int pro = 0;
    
    for(auto x:v)
    {
        currTime += x.first;
        pro += (x.second - currTime);
    }
    
    cout<<pro<<endl;
    return 0;
}
