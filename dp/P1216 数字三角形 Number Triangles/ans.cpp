#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r;
    cin >> r;
    vector<vector<int>> dp(r, vector<int>(r)), m(r, vector<int>(r));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> m[i][j];
        }
    }

    dp[0][0] = m[0][0];
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) 
                dp[i][j] = dp[i - 1][j] + m[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + m[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + m[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < r; i++)
        ans = max(ans, dp[r - 1][i]);

    cout << ans;


    return 0;
}