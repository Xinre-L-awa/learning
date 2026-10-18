#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
ll fact[1000005];
ll invf[1000005];

ll qpow(ll n, ll p) {
    ll ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * n % MOD;
        n = n * n % MOD;        
        p >>= 1;
    }

    return ans;
}

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) 
        fact[i] = i * fact[i - 1] % MOD;

    invf[n] = qpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        invf[i] = (i + 1) * invf[i + 1] % MOD;
}

int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;

    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        n -= t;
    }

    init(n);
    cout << C(n - 1, m - 1);

    return 0;
}