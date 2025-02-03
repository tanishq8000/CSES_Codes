#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> adj[n];
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }
    
    vector<vector<int>> dist(n,vector<int>(2,LLONG_MAX));
    priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<>> pq;
    
    pq.push({0,{0,0}});
    dist[0][0] = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int d = it.first;
        int node = it.second.first;
        bool coupan = it.second.second;
        
        if(d > dist[node][coupan]) continue;
        
        for(auto x : adj[node]){
            int adjNode = x.first;
            int cost = x.second;
            
            if(dist[adjNode][coupan] > d + cost){
                dist[adjNode][coupan] = d + cost;
                pq.push({d+cost , {adjNode,coupan}});
            }
            
            if(!coupan && dist[adjNode][1] > d + (cost/2)){
                dist[adjNode][1] = d + (cost / 2);
                pq.push({dist[adjNode][1],{adjNode,1}});
            }
        }
    }
    
    cout<<min(dist[n-1][0],dist[n-1][1])<<endl;
    return 0;
}
