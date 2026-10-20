#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; ll m;
    cin >> n >> m;
    vector<ll> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    ll lo = 0, hi = *max_element(t.begin(), t.end()), ans = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll wood = 0;
        for (int i = 0; i < n; i++)
            if (t[i] > mid) wood += t[i] - mid;
        if (wood >= m) { ans = mid; lo = mid + 1; }  // 够，试着更高
        else hi = mid - 1;                            // 不够，降低
    }
    cout << ans;
    return 0;
}