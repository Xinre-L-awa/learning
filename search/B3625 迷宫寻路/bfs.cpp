#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

int n, m;
// int a[102][102];
bool ok[103][103] = {false};
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bfs(int x, int y) {
    queue<point> q;
    q.push({1, 1});
    ok[1][1] = false;
    while (!q.empty()) {
        point p = q.front();
        q.pop();
        if (p.x == n && p.y == m) return true;
        ok[p.x][p.y] = false;
        for (int i = 0; i < 4; i++) {
            if (ok[p.x + d[i][0]][p.y + d[i][1]]) {
                ok[p.x + d[i][0]][p.y + d[i][1]] = false;
                q.push({p.x + d[i][0], p.y + d[i][1]});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '.') ok[i][j] = true;
        }
    }

    cout << (bfs(1, 1) ? "Yes" : "No");


    return 0;
}