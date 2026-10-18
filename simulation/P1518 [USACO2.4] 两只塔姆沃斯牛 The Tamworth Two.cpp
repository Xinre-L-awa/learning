#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> m(10);
    for (int i = 0; i < 10; i++) cin >> m[i];

    int fx, fy, cx, cy;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (m[i][j] == 'F') { fx = i; fy = j; }
            else if (m[i][j] == 'C') { cx = i; cy = j; }
        }

    // 北、东、南、西（顺时针）
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int df = 0, dc = 0;   // 初始都朝北

    for (int t = 1; t <= 200000; t++) {
        // ---- FJ 移动（基于旧状态）----
        int nfx = fx + dx[df], nfy = fy + dy[df];
        if (nfx < 0 || nfx > 9 || nfy < 0 || nfy > 9 || m[nfx][nfy] == '*') {
            df = (df + 1) % 4;      // 撞墙/障碍，只转向，不移动
        } else {
            fx = nfx; fy = nfy;
        }

        // ---- 牛移动（基于旧状态，地图只有 * 障碍）----
        int ncx = cx + dx[dc], ncy = cy + dy[dc];
        if (ncx < 0 || ncx > 9 || ncy < 0 || ncy > 9 || m[ncx][ncy] == '*') {
            dc = (dc + 1) % 4;
        } else {
            cx = ncx; cy = ncy;
        }

        // ---- 分钟末统一判相遇 ----
        if (fx == cx && fy == cy) {
            cout << t;
            return 0;
        }
    }

    cout << 0;
    return 0;
}