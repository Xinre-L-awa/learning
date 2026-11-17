#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        
        int d = 0;
        while (n >> (d + 1) > 0) d++;
        
        int m = 0;
        for (int i = 1; i <= n; i++) m ^= i;

        for (int k = d + 1; k >= 1; k--) {
            if ((m & (1 << k)) == 0) {
                int x = 1 << (k - 1);
                if (x <= n) {
                    a[x - 1] = 1;     // 标记数字 x 需要翻倍
                    m ^= x;         // 从异或和里去掉 x
                    m ^= (x << 1);  // 从异或和里加上 2x
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }
    }


    return 0;
}