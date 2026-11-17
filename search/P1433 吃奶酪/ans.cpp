#include <bits/stdc++.h>
using namespace std;

double a[15], b[15];
double dis(int x, int y) {
    return sqrt((a[x]-a[y])*(a[x]-a[y]) + (b[x]-b[y])*(b[x]-b[y]));
}

double dp[1 << 16][20];
double ans = 1e12;
int n;
bool vis[20] = {false};
void dfs(int t, int i, int m, double s) {
    if (s > ans) return;
    if (t == n) {
        ans = min(ans, s);
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (vis[j]) continue;

        int p = m | (1 << j);
        double d = s + dis(j, i);
        if (dp[p][j] != 0 && dp[p][j] <= d) continue;
        vis[j] = true;
        dp[p][j] = d;
        dfs(t + 1, j, p, d);
        vis[j] = false;
    }
}

int main() {
    scanf("%d", &n);
    a[0] = b[0] = 0;                            // 明确原点
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &a[i], &b[i]);

    dfs(0, 0, 0, 0.0);
    printf("%.2f", ans);

    return 0;
}