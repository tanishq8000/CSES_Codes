#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int32_t main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> dist(n+1,LLONG_MAX);
    
    dist[1] = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int d = it.first;
        int node = it.second;
        
        if (d > dist[node]) continue;
        
        for(auto x : adj[node]){
            int adDist = d + x.second;
            int adNode = x.first;
            
            if(dist[adNode] > adDist){
                dist[adNode] = adDist;
                pq.push({adDist,adNode});
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
