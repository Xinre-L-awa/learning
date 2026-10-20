#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        ll n, x;
        cin >> n >> x;
        int k = 0;
        while (k < n && (k | x) == x) k++;

        if (k < n) {
            for (int i = 0; i < k; i++) cout << i << ' ';
            for (int i = 0; i <= n - (k - 0 + 1) - 1; i++) cout << 0 << ' ';
            cout << x << '\n';
        } else {
            ll pre = 0;
            for (int i = 0; i < n - 1; i++) {
                cout << i << ' ';
                pre |= i;
            }
            if (((pre | (n - 1))) == x) {
                cout << n - 1 << '\n';
            }else 
                cout << x << '\n';
        }
    }

    return 0;
}
