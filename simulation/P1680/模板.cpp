#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;   // 预处理上限
const ll MOD = 1e9 + 7;     // 必须是素数

ll fact[MAXN];      // fact[i] = i! mod MOD
ll inv_fact[MAXN];  // inv_fact[i] = (i!)^{-1} mod MOD

// 快速幂：a^b mod MOD
ll qpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 预处理，O(n + log MOD)
void init(int n) {
    // 1. 算阶乘
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i-1] * i % MOD;

    // 2. 用费马小定理求最后一个逆元
    inv_fact[n] = qpow(fact[n], MOD - 2);

    // 3. 倒推所有逆元
    for (int i = n; i >= 1; i--)
        inv_fact[i-1] = inv_fact[i] * i % MOD;
}

// 查询 C(n, m)，O(1)
ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fact[n] * inv_fact[m] % MOD * inv_fact[n-m] % MOD;
}

int main() {
    init(1000000);           // 一次性预处理
    cout << C(10, 3) << "\n"; // 120
    cout << C(100, 50) << "\n";
    return 0;
}