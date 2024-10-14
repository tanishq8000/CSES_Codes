#include <bits/stdc++.h>
using namespace std;
#define int long long int

void helper(int disk,int l,int r,int m,vector<vector<int>> &moves)
{
    if(disk==1)
    {
        moves.push_back({l,r});
        return;
    }
    
    helper(disk-1,l,m,r,moves);
    moves.push_back({l,r});
    helper(disk-1,m,r,l,moves);
}

int32_t main() {
    int n;
    cin>>n;
    
    vector<vector<int>> moves;
    
    helper(n,1,3,2,moves);
    
    cout<<moves.size()<<endl;
    for(auto x:moves)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    
    return 0;
}
