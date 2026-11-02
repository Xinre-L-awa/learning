// 此题解为 O(n^2) 解法

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // 长度
    string s; // 字符串
    cin >> n >> s;

    vector<int> dp(n + 1);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (s[j] <= s[i]) { // 思考为什么当 a_j1, a_j2都小于 a_i, 但是 a_j2 小于 a_j1时，方程仍然成立
                dp[i] = max(dp[i], dp[j] + 1);
                
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;


    return 0;
}