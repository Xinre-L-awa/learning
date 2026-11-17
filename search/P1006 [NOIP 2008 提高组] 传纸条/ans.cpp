#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[55][55];
int dp[105][55][55];
bool vis[105][55][55];

// 两人都走 k 步（x+y=k），分别在第 x1、x2 行
// 返回：从下一步开始到终点的最大收益（不含当前位置）
int dfs(int k, int x1, int x2) {
    if (k == m + n) return 0;                 // 两人都到 (m,n)

    if (vis[k][x1][x2]) return dp[k][x1][x2];
    vis[k][x1][x2] = true;

    int best = 0;

    // 第一人：d1=0 向右，d1=1 向下
    for (int d1 = 0; d1 <= 1; ++d1) {
        int nx1 = x1 + d1;
        int ny1 = k + 1 - nx1;
        if (nx1 < 1 || nx1 > m || ny1 < 1 || ny1 > n) continue;

        // 第二人：d2=0 向右，d2=1 向下
        for (int d2 = 0; d2 <= 1; ++d2) {
            int nx2 = x2 + d2;
            int ny2 = k + 1 - nx2;
            if (nx2 < 1 || nx2 > m || ny2 < 1 || ny2 > n) continue;

            int add = a[nx1][ny1] + a[nx2][ny2];
            if (nx1 == nx2 && ny1 == ny2) {
                add -= a[nx1][ny1];           // 同格只算一次
            }

            best = max(best, add + dfs(k + 1, nx1, nx2));
        }
    }

    return dp[k][x1][x2] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    // 两条路径都从 (1,1) 出发，起点值加一次
    cout << dfs(2, 1, 1) << '\n';

    return 0;
}