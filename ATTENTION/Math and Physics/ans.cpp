#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    bool all_one = true;
    bool internal_non_one = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] != 1) all_one = false;
        // 判断是否存在内部的大于 1 的核
        if (i > 0 && i < n - 1 && a[i] != 1) {
            internal_non_one = true;
        }
    }

    if (all_one) {
        cout << -1 << '\n';
    } else if (internal_non_one) {
        cout << sum - 1 << '\n';
    } else {
        cout << sum - (n - 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}