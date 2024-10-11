#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<string> helper(int n)
{
    if(n==1)
    {
        return {"0","1"};
    }
    
    vector<string> prev = helper(n-1);
    
    vector<string> rprev = prev;
    reverse(rprev.begin(),rprev.end());
    
    int sz = prev.size();
    int idx = 0;
    
    while(idx < sz)
    {
        string temp = "0" + prev[idx];
        prev[idx] = "1" + rprev[idx];
        prev.push_back(temp);
        idx++;
    }
    return prev;
}

int32_t main() {
    int n;
    cin>>n;
    
    vector<string> ans = helper(n);
    
    for(auto x:ans)
    {
        cout<<x<<endl;
    }
    return 0;
}
