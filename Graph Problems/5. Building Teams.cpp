#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int team, vector<vector<int>>& graph, vector<int>& teams) {
    teams[node] = team;

    for (int neighbor : graph[node]) {
        if (teams[neighbor] == 0) {
            if (!dfs(neighbor, 3 - team, graph, teams)) {
                return false;
            }
        } else if (teams[neighbor] == team) {
            return false;
        }
    }

    return true;
}

bool divideTeams(int n, int m, vector<pair<int, int>>& friendships) {
    vector<vector<int>> graph(n + 1);
    
    for (auto& edge : friendships) {
        int a = edge.first, b = edge.second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> teams(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (teams[i] == 0) {
            if (!dfs(i, 1, graph, teams)) {
                cout << "IMPOSSIBLE\n";
                return false;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << teams[i] << " ";
    }
    cout << "\n";
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> friendships(m);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        friendships[i] = {a, b};
    }

    divideTeams(n, m, friendships);

    return 0;
}
