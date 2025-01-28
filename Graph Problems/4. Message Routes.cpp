#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    vector<int> vis(n,0);
    vector<int> pre(n,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int dist = it.first;
        int node = it.second;
        
        for(auto x : adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push({dist+1,x});
                pre[x] = node;
                
                if(x == n-1){
                    cout<<dist+2<<endl;
                    vector<int> path(dist+2);
                    path[0] = x+1;
                    int idx = 1;
                    while(pre[x] != 0){
                        path[idx] = pre[x]+1;
                        idx++;
                        x = pre[x];
                    }
                    path[idx] = 1;
                    
                    for(int i=dist+1;i>=0;i--){
                        cout<<path[i]<<" ";
                    }
                    return 0;
                }
            }
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
