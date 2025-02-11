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
    
    vector<int> dist(n,-1e9), par(n,-1),topo;
    queue<int> q;
    
    for(int i=0;i<n;i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    
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
    
    dist[0] = 0;
    
    for(auto it : topo){
        if(dist[it] == -1e9){
            continue;
        }
        
        for(auto x : adj[it]){
            if(dist[x] < dist[it] + 1){
                dist[x] = dist[it] + 1;
                par[x] = it;
            }
        }
    }
    
    
    if(dist[n-1] == -1e9){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    vector<int> path;
    
    for(int curr = n-1 ; curr != -1 ; curr = par[curr]){
        path.push_back(curr);
    }
    
    int pathLen = path.size();
    
    cout<<pathLen<<endl;
    for(int i=pathLen-1;i>=0;i--){
        cout<<path[i]+1<<" ";
    }
    cout<<endl;
    
    return 0;
}
