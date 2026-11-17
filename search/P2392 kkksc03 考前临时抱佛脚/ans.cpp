#include <bits/stdc++.h>
using namespace std;

int s[4] = {0}, p[4][20] = {0};
int t = INT_MAX;
void dfs(int n, int i, int k, int l, int r) {
    if (i == n) {
        t = min(t, max(l, r));
        return;
    }

    dfs(n, i + 1, k, l + p[k][i], r);
    dfs(n, i + 1, k, l, r + p[k][i]);
}

int main() {
    int ans = 0;
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> p[i][j];
        }
        dfs(s[i], 0, i, 0, 0);
        ans += t;
        t = INT_MAX;
    }

    cout << ans;

    return 0;
}