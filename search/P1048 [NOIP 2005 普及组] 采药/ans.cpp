#include <bits/stdc++.h>
using namespace std;

int m, t;
int cost[105], val[105];
bool vis[105][1001] = {false};
int mem[101][1001] = {0};

int dfs(int i, int r) {
    if (i == m) return 0;
    if (vis[i][r]) return mem[i][r];
    vis[i][r] = true;

    int v = dfs(i + 1, r);
    if (r >= cost[i]) {
        v = max(v, dfs(i + 1, r - cost[i]) + val[i]);
    }

    return mem[i][r] = v;
}

int main() {
    cin >> t >> m;
    for (int i = 0; i < m; ++i) cin >> cost[i] >> val[i];
    cout << dfs(0, t);
    return 0;
}