#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isSquare(ll n) {
    ll r = sqrtl((long double)n);
    while ((r + 1) * (r + 1) <= n) ++r;
    while (r * r > n) --r;
    return r * r == n;
}

bool isSumOfTwoSquares(ll n) {
    for (ll a = 1; a * a < n; ++a) {
        if (isSquare(n - a * a)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (isSquare(n)) {
        cout << 1 << '\n';
    } else if (isSumOfTwoSquares(n)) {
        cout << 2 << '\n';
    } else {
        ll t = n;
        while (t % 4 == 0) t /= 4;

        if (t % 8 == 7) {
            cout << 4 << '\n';
        } else {
            cout << 3 << '\n';
        }
    }

    return 0;
}