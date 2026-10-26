#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, n, a, b;
    cin >> k >> n >> a >> b;
    
    if (n * b >= k) {
        cout << -1 << "\n";
        return;
    }
    
    // 根据总电量推导出的最大 x
    long long max_x1 = (k - 1 - n * b) / (a - b);
    // 根据过程中不卡死推导出的最大 x
    long long max_x2 = (k + a - 1) / a - 1; 
    // 注意这里 (k - 1) / a 也是对的，因为需要严格大于 a。
    // 实际上更严谨的写法是 (k - 1) / a，因为 x*a < k，x < k/a，所以 x <= (k-1)/a
    // 但我上面的推导过程是 (mid-1)*a + (n-mid)*b < k，实际上化简为 x*a <= k+a-1 略有冗余，直接用 (k-1)/a 是没问题的。
    
    long long ans = min({n, max_x1, max_x2});
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}