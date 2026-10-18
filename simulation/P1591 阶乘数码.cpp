#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> multiply(string a, string b) {
    if (a == "0" || b == "0") return {0};

    int l1 = a.size(), l2 = b.size();
    vector<int> A(l1), B(l2), ans(l1 + l2, 0);

    // 倒序：下标 0 是个位
    for (int i = 0; i < l1; i++) A[i] = a[l1 - 1 - i] - '0';
    for (int j = 0; j < l2; j++) B[j] = b[l2 - 1 - j] - '0';

    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
            ans[i + j] += A[i] * B[j];   // ✅ 经典写法

    // 进位
    int carry = 0;
    for (int k = 0; k < l1 + l2; k++) {
        ans[k] += carry;
        carry = ans[k] / 10;
        ans[k] %= 10;
    }

    // 去前导 0（高位在末尾）
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();

    reverse(ans.begin(), ans.end());   // 恢复正序输出
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<pair<int,int>> qs(t);
    int maxN = 1;
    for (auto &[n, a] : qs) { cin >> n >> a; maxN = max(maxN, n); }

    // 预处理所有 i! 到 maxN（存起来）
    vector<string> fac(maxN + 1);
    fac[0] = fac[1] = "1";
    for (int i = 2; i <= maxN; i++) {
        vector<int> v = multiply(fac[i-1], to_string(i));
        string s;
        for (int d : v) s += char('0' + d);
        fac[i] = s;
    }

    for (auto [n, a] : qs) {
        int ans = 0;
        for (char c : fac[n]) if (c - '0' == a) ans++;
        cout << ans << '\n';
    }
    return 0;
}