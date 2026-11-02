#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;
        map<tuple<int, int, int>, int> cnt;
        map<tuple<int, int, int>, int> c;

        for (int i = 0; i < n - 2; i++) {
            int x = a[i], y = a[i+1], z = a[i+2];

            ans += cnt[{x, y, 0}];
            ans += cnt[{x, z, 1}];
            ans += cnt[{y, z, 2}];

            ans -= 3LL * c[{x, y, z}];

            cnt[{x, y, 0}]++;
            cnt[{x, z, 1}]++;
            cnt[{y, z, 2}]++;
            c[{x, y, z}]++;
        }

        cout << ans << '\n';
    }
    return 0;
}