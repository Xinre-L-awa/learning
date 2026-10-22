#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(const vector<int>& a, int k) {
    ll ans = 0;
    for (const int& i : a) {
        ans += i / k;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> L(n);
    int h = 0;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> L[i];
        s += L[i];
        h = max(h, L[i]); // 此处最初写的是 min(h, L[i] / k), 然后是 max(h, L[i] / k)，
                          // 前者只是保证每根木头都能切，后者在此基础上扩大了范围，但二者
                          // 没有考虑到当 l > L[i] 时，第i根木头切割结果为0
    }

    int l = 0, r = h, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid == 0) break;
        ll t = f(L, mid);
        if (t >= k) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
}