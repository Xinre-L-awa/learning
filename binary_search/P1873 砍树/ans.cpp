#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> t(n);
    vector<ll> pre(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());
    pre[0] = t[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + t[i];

    int ans = 0;
    ll s = pre[n - 1];
    while (true) {
        
        int idx = upper_bound(t.begin(), t.end(), ans) - t.begin();
        s = idx == 0 ?
            (n - idx) * ans
        :   pre[idx - 1] + (ll)(n - idx) * ans;
        s = pre[n - 1] - s;
        if (s >= m)
            ans++;
        else break;
    }

    cout << ans - 1;

    return 0;
}