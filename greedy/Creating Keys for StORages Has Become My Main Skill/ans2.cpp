#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;

        vector<int> a;
        int cur_or = 0;
        int i = 0;

        // 尽可能放连续整数
        while ((int)a.size() < n && (i | x) == x) {
            a.push_back(i);
            cur_or |= i;
            i++;
        }

        if ((int)a.size() < n) {
            // 遇到了非子掩码 i，停止时 a = [0,1,...,i-1]
            // 下一个位置放 x，剩余补 0
            a.push_back(x);
            while ((int)a.size() < n) a.push_back(0);
        } else {
            // 放满了 n 个，a = [0,1,...,n-1]
            if (cur_or != x) {
                // 把最后一个改成 x
                a.back() = x;
            }
        }

        for (int j = 0; j < n; j++) {
            if (j) cout << ' ';
            cout << a[j];
        }
        cout << '\n';
    }
    return 0;
}