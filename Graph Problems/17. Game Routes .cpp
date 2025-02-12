#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n];
    vector<int> ind(n,0);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        ind[b-1]++;
    }
    
    queue<int> q;
    
    for(int i=0;i<n;i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        topo.push_back(node);
        
        for(auto x : adj[node]){
            ind[x]--;
            if(ind[x] == 0){
                q.push(x);
            }
        }
    }
    
    int sz = topo.size();
    
    int mod = 1e9 + 7;
    vector<int> dp(n,0);
    
    dp[n-1] = 1;
    
    for(int i=sz-1;i>=0;i--){
        for(int j=0;j<adj[topo[i]].size();j++){
            dp[topo[i]] += (dp[adj[topo[i]][j]] % mod);
        }
    }
    
    cout<<dp[0] % mod<<endl;
    
    return 0;
}
