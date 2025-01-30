#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mxn = 1e5;
int p[mxn];
vector<int> adj[mxn],ans;
bool vis[mxn];

void dfs(int u,int pu = -1){
    p[u] = pu;
    vis[u] = 1;
    
    for(int v : adj[u]){
        if(v == pu){
            continue;
        }
        
        if(vis[v]){
            int u2 = u;
            while(u ^ v){
                ans.push_back(u);
                u = p[u];
            }
            ans.push_back(v);
            ans.push_back(u2);
            
            cout<<ans.size()<<endl;
            for(int a : ans){
                cout<<a+1<<" ";
            }
            cout<<endl;
            exit(0);
        }
        else{
            dfs(v,u);
        }
    }
}

int32_t main() {
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        
        --a;
        --b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;
    
    return 0;
}
