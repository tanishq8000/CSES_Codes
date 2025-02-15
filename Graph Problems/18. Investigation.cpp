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
    
    vector<int> dist(n,1e18),ways(n,0),minFlights(n,1e18),maxFlights(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    dist[0] = 0;
    ways[0] = 1;
    minFlights[0] = 0;
    maxFlights[0] = 0;
    
    int mod = 1e9+7;
    
    pq.push({0,0});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int p = it.first;
        int node = it.second;
        
        if(p > dist[node]) continue;
        
        for(auto x:adj[node]){
            int curr = x.second;
            int adNode = x.first;
            
            if(p+curr < dist[adNode]){
                dist[adNode] = p + curr;
                pq.push({p+curr,adNode});
                
                ways[adNode] = ways[node];
                minFlights[adNode] = minFlights[node] + 1;
                maxFlights[adNode] = maxFlights[node] + 1;
            }
            else if(p+curr == dist[adNode]){
                ways[adNode] = (ways[adNode] + ways[node]) % mod;
                minFlights[adNode] = min(minFlights[adNode],minFlights[node]+1);
                maxFlights[adNode] = max(maxFlights[adNode],maxFlights[node]+1);
            }
        }
    }
    
    cout<<dist[n-1]<<" "<<ways[n-1]<<" "<<minFlights[n-1]<<" "<<maxFlights[n-1]<<endl;
    return 0;
}
