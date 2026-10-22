#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if (it != a.end() && it != a.begin()) ans += min(abs(*it - b[i]), 
                                                         abs(*(it - 1) - b[i]));
        else if (it == a.end()) ans += abs(*(it - 1) - b[i]);
        else ans += abs(*it - b[i]);
    }

    cout << ans;

    return 0;
}