#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<int> a(m), b(m);
    
    // 输入第一行和第二行
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    // 计算第二行的前缀和 (pre_b[i] 表示 b[0] 到 b[i-1] 的和)
    vector<long long> pre_b(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pre_b[i + 1] = pre_b[i] + b[i];
    }

    // 计算第一行的后缀和 (suf_a[i] 表示 a[i] 到 a[m-1] 的和)
    vector<long long> suf_a(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
        suf_a[i] = suf_a[i + 1] + a[i];
    }

    long long ans = 1e18; // 初始化一个很大的数，用来找最小值

    // 枚举 Alice 在第 k 列向下走 (k 从 0 到 m-1)
    for (int k = 0; k < m; k++) {
        // Bob 走左边的策略：拿第 2 行前 k 个 (下标 0 到 k-1)
        long long bob_left = pre_b[k]; 
        
        // Bob 走右边的策略：拿第 1 行 k 之后的部分 (下标 k+1 到 m-1)
        long long bob_right = suf_a[k + 1]; 

        // Bob 很聪明，他会选能拿更多的那条路
        long long bob_score = max(bob_left, bob_right);

        // Alice 要尽量让 Bob 拿得少
        ans = min(ans, bob_score);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}