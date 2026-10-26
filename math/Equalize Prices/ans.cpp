#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        if (a[n - 1] - a[0] > 2 * k) {
            cout << -1 << '\n';
            continue;
        }

        cout << a[0] + k << '\n';
    }

    return 0;
}
