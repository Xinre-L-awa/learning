#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(n), b(m), c(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < k; i++) cin >> c[i];
        
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        vector<ll> d(n - 1);
        for (int i = 0; i < n - 1; i++) d[i] = a[i + 1] - a[i];

        // 1. 查找最大差值及其出现次数和位置
        ll max_diff = 0;
        int idx = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (d[i] > max_diff) {
                max_diff = d[i];
                idx = i;
                cnt = 1;
            } else if (d[i] == max_diff) {
                cnt++;
            }
        }

        // 如果最大差值出现多次，插入一个数无法消除所有最大差值，答案就是最大差值本身
        if (cnt > 1) {
            cout << max_diff << '\n';
            continue;
        }

        // 2. 查找第二大差值（排除最大差值所在的那个区间）
        ll d2 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i != idx) {
                d2 = max(d2, d[i]);
            }
        }

        ll ans = max_diff;
        ll L = a[idx], R = a[idx + 1];

        // 3. 遍历 b，寻找最接近中点的插入值
        for (int i = 0; i < m; i++) {
            // 目标值：让 b[i] + c[j] 尽可能靠近 L 和 R 的中点
            ll target = (L + R) / 2 - b[i];
            auto it = lower_bound(c.begin(), c.end(), target);
            
            // 检查 lower_bound 找到的位置
            if (it != c.end()) {
                ll val = b[i] + *it;
                if (val >= L && val <= R) {
                    ans = min(ans, max({d2, val - L, R - val}));
                }
            }
            
            // 检查 lower_bound 找到位置的前一个元素（可能更接近中点）
            if (it != c.begin()) {
                auto it2 = prev(it);
                ll val = b[i] + *it2;
                if (val >= L && val <= R) {
                    ans = min(ans, max({d2, val - L, R - val}));
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}