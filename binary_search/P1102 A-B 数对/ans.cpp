#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll target = a[i] + c;                       // A = B + C
        auto lo = lower_bound(a.begin(), a.end(), target);
        auto hi = upper_bound(a.begin(), a.end(), target);
        ans += hi - lo;                             // 该 target 出现几次就贡献几对
    }
    cout << ans << '\n';
    return 0;
}