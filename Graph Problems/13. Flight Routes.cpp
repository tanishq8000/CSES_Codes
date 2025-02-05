#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector < pair < int, int >> adj[n];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c });
    }

    priority_queue < pair < int, int > , vector < pair < int, int >> , greater < pair <int, int >>> pq;
    pq.push({0,0});

    vector<vector<int>> dist(n);

    while (!pq.empty()) {
        auto [p,node] = pq.top();
        pq.pop();
        
        if(dist[node].size() >= k ) continue;
        
        dist[node].push_back(p);

        for (auto x: adj[node]) {
            int price = x.second;
            int adNode = x.first;
            pq.push({p + price,adNode});
        }
    }

    for(int i=0;i<dist[n-1].size();i++){
        cout<<dist[n-1][i]<<" ";
    }
    return 0;
}