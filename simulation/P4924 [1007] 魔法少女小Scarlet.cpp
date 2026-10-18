#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n, m;
int a[MAXN][MAXN];
int tmp[MAXN][MAXN];   // 复用临时数组

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 初始填充 1 ~ n^2，从左到右、从上到下
    int val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = val++;

    while (m--) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;

        int len = 2 * r + 1;
        int top = x - r;     // 子矩阵左上角行
        int left = y - r;    // 子矩阵左上角列

        // 把子矩阵按旋转规则放入 tmp
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int ni, nj;
                if (z == 0) {
                    // 顺时针 90°
                    ni = j;
                    nj = len - 1 - i;
                } else {
                    // 逆时针 90°
                    ni = len - 1 - j;
                    nj = i;
                }
                tmp[ni][nj] = a[top + i][left + j];
            }
        }

        // 写回原矩阵
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                a[top + i][left + j] = tmp[i][j];
    }

    // 输出最终矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << (j == n ? '\n' : ' ');
        }
    }

    return 0;
}