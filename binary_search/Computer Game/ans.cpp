#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        ll k, n, a, b;
        cin >> k >> n >> a >> b;

        if (k <= n * b) {
            cout << -1 << '\n';
            continue;
        }

        ll l = 0, r = n, ans = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (mid * a + (n - mid) * b <= k - 1) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}