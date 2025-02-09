#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector < int > adj[n];
    vector < int > ind(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        ind[b - 1]++;
    }

    queue < int > q;

    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    vector < int > topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (auto x: adj[node]) {
            ind[x]--;
            if (ind[x] == 0) {
                q.push(x);
            }
        }
    }

    if (topo.size() == n) {
        for (auto x: topo) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;

}