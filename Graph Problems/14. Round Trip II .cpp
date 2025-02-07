#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool dfsCheck(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis,vector<int> &par,vector<int> &cycle) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it: adj[node]) {
        if (!vis[it]) {
            par[it] = node;
            if (dfsCheck(it, adj, vis, pathVis, par,cycle) == true)
                return true;
        }
        else if (pathVis[it]) {
            int cur = node;
            while (cur != it) {
                cycle.push_back(cur);
                cur = par[cur];
            }
            cycle.push_back(it);
            cycle.push_back(node);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector < int > adj[n];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    
    vector<int> vis(n,0),pathVis(n,0),par(n,0);
    vector<int> cycle;
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis,par,cycle) == true){
                cout<<cycle.size()<<endl;
                for(auto x:cycle){
                    cout<< x+1 <<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}