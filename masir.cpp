#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 500;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<vector<char>> grid;
vector<vector<int>> component;
int n, m;

void bfs(int x, int y, int comp_id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    component[x][y] = comp_id;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && component[nx][ny] == -1) {
                component[nx][ny] = comp_id;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    component.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int comp_id = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && component[i][j] == -1) {
                bfs(i, j, comp_id++);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1; --c1; --r2; --c2;
        if (component[r1][c1] != -1 && component[r1][c1] == component[r2][c2]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
