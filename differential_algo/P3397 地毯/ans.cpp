// 这个答案是错的

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int k = 0; k < m; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        vector<vector<int>> flag(n, vector<int>(n, 0));
        for (int i = x1 - 1; i <= x2 - 1; i++) {
            flag[i][y1 - 1]++;
            if (y2 - 1 < n)flag[i][y2 - 1]--;
        }

        for (int i = x1 - 1; i <= x2 - 1; i++) {
            for (int j = y1 - 1; j < n && j < y2; j++) {
                ans[i][j] += flag[i][y1 - 1] + flag[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << (j == n - 1 ? '\n' : ' ');


    return 0;
}