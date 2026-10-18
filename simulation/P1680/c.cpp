#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fact[MAXN];
ll inv_fact[MAXN];

ll qpow(int a, int b) {
    ll ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

// 费马小定理计算逆元
ll inv(ll a, ll p) {
    return qpow(a, p - 2);
}

int main() {
    ll n, m;
    cin >> n >> m;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) 
        fact[i] = i * fact[i - 1];
    inv_fact[n] = inv(fact[n], MOD);
    for (int i = n; i >= 1; i++)
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    
    if (m < 0 || m > n) return 0;
    int ans = fact[n] * inv_fact[n - m] % MOD * inv_fact[m] % MOD;

    return 0;
}
