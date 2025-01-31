#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Position {
    int x, y;
};

int n, m;
vector<string> labyrinth;
vector<vector<int>> monster_time;
vector<vector<int>> player_time;
vector<vector<char>> parent;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] == '.';
}

void bfs_monsters(queue<Position>& q) {
    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (is_valid(nx, ny) && monster_time[nx][ny] > monster_time[curr.x][curr.y] + 1) {
                monster_time[nx][ny] = monster_time[curr.x][curr.y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfs_player(Position start, Position& exit, string& path) {
    queue<Position> q;
    q.push(start);
    player_time[start.x][start.y] = 0;

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        if (curr.x == 0 || curr.x == n - 1 || curr.y == 0 || curr.y == m - 1) {
            exit = curr;
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (is_valid(nx, ny) && player_time[nx][ny] == -1 && player_time[curr.x][curr.y] + 1 < monster_time[nx][ny]) {
                player_time[nx][ny] = player_time[curr.x][curr.y] + 1;
                parent[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    labyrinth.resize(n);
    monster_time.assign(n, vector<int>(m, 1e9));
    player_time.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<char>(m, 0));

    Position start;
    queue<Position> monsters;

    for (int i = 0; i < n; ++i) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; ++j) {
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
                labyrinth[i][j] = '.';
            } else if (labyrinth[i][j] == 'M') {
                monsters.push({i, j});
                monster_time[i][j] = 0;
            }
        }
    }

    bfs_monsters(monsters);

    Position exit;
    string path;

    if (bfs_player(start, exit, path)) {
        cout << "YES\n";

        // Reconstruct the path
        Position curr = exit;
        while (curr.x != start.x || curr.y != start.y) {
            for (int i = 0; i < 4; ++i) {
                int px = curr.x - dx[i];
                int py = curr.y - dy[i];
                if (is_valid(px, py) && player_time[px][py] == player_time[curr.x][curr.y] - 1 && parent[curr.x][curr.y] == dir[i]) {
                    path += dir[i];
                    curr = {px, py};
                    break;
                }
            }
        }

        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}