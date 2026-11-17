#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
int m[10][10] = {0};
int dp[22][10][10];
bool vis[22][10][10];

int dfs(int k, int x1, int x2) {
    if (k == 2 * n) return 0;

    if (vis[k][x1][x2]) return dp[k][x1][x2];
    int best = 0;
    vis[k][x1][x2] = true;
    for (int d1 = 0; d1 <= 1; d1++) {
        int xa = x1 + d1;
        int ya = (k - x1) + (1 - d1);
        if (xa < 1 || xa > n || ya < 1 || ya > n) continue;
        for (int d2 = 0; d2 <= 1; d2++) {
            int xb = x2 + d2;
            int yb = (k - x2) + (1 - d2);
            if (xb < 1 || xb > n || yb < 1 || yb > n) continue;

            int add = m[xa][ya] + m[xb][yb];
            if (xa == xb && ya == yb) add /= 2;
            best = max(best, add + dfs(k + 1, xa, xb));
        }
    }

    return dp[k][x1][x2] = best;
}

int main() {
    cin >> n;
    
    int x, y, v;
    while (cin >> x >> y >> v) {
        m[x][y] = v;
    }

    cout << m[1][1] + dfs(2, 1, 1);

    return 0;
}