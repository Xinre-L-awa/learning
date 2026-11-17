#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans = INT_MAX;
int k[201];
int dist[201];          // dist[l] = 到 l 楼最少步数，INF = 未访问

void dfs(int l, int cnt) {
    if (cnt >= ans) return;                 // ① 最优性剪枝
    if (l == b) { ans = cnt; return; }      // ② 先判到达
    if (cnt >= dist[l]) return;             // ③ 已有更优/相等路径才剪
    dist[l] = cnt;                          // ④ 记录更优值，继续搜

    int step = k[l];
    if (step == 0) return;                  // ⑤ 原地不动
    if (l - step >= 1) dfs(l - step, cnt + 1);
    if (l + step <= n) dfs(l + step, cnt + 1);
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> k[i];

    fill(dist, dist + 201, INT_MAX);        // ✅ 全 INF
    // ❌ 不要写 dist[a] = 0，让 dfs 自己写
    dfs(a, 0);
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}