#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 多开一行一列，避免边界特判（下标 1..n 使用，0 行/列不用）
    vector<vector<long long>> d(n + 2, vector<long long>(n + 2, 0));

    for (int k = 0; k < m; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 二维差分：矩形 [x1..x2] × [y1..y2] 加 1
        d[x1][y1]         += 1;
        d[x1][y2 + 1]     -= 1;
        d[x2 + 1][y1]     -= 1;
        d[x2 + 1][y2 + 1] += 1;
    }

    // 二维前缀和还原
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }

    // 输出
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << (j == n ? '\n' : ' ');
        }
    }

    return 0;
}