#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y;
};

int n, m, x, y;
int a[404][404];
int d[8][2] = {
    {2, 1}, {2, -1},
    {1, 2}, {1, -2},
    {-2, 1}, {-2, -1},
    {-1, 2}, {-1, -2}
};
vector<vector<bool>> vis;

bool ok(int x, int y) {
    return (x > 0 && x <= n && y > 0 && y <= m) && !vis[x][y];
}

void bfs(int xa, int ya) {
    vis = vector<vector<bool>>(n + 2, vector<bool>(m + 2, false));
    queue<node> q;
    q.push({xa, ya});
    vis[xa][ya] = true;
    a[xa][ya] = 0;
    while (!q.empty()) {
        node p = q.front(); q.pop();
        
        for (int i = 0; i < 8; i++) {
            int xn = p.x + d[i][0], yn = p.y + d[i][1];
            if (ok(xn, yn)) {
                q.push({xn, yn});
                a[xn][yn] = a[p.x][p.y] + 1;
                vis[xn][yn] = true;
            }
        }
    }
}

int main() {
    memset(a, -1, sizeof(a));
    cin >> n >> m >> x >> y;

    bfs(x, y);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d", a[i][j]);
            putchar(j == m ? '\n' : ' ');
        }
    }

    return 0;
}