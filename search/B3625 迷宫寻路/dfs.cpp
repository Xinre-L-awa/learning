#include <bits/stdc++.h>
using namespace std;

int n, m;
// int a[102][102];
bool ok[103][103] = {false};
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bfs(int x, int y) {
    if (x == n && y == m) return true;

    for (int i = 0; i < 4; i++) {
        if (ok[x + d[i][0]][y + d[i][1]]) {
            ok[x + d[i][0]][y + d[i][1]] = false;
            if (bfs(x + d[i][0], y + d[i][1])) return true;
            //ok[x + d[i][0]][y + d[i][1]] = true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '.') ok[i][j] = true;
        }
    }

    cout << (bfs(1, 1) ? "Yes" : "No");


    return 0;
}