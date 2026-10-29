#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    // 使用 set 存储当前可能持球的玩家编号，自动去重且有序
    set<int> cur;
    cur.insert(x);

    for (int i = 0; i < m; i++) {
        int r;
        char c;
        cin >> r >> c;

        set<int> nxt; // 下一轮可能持球的玩家集合

        for (int p : cur) {
            if (c == '0') {
                // 顺时针
                int nxt_p = (p - 1 + r) % n + 1;
                nxt.insert(nxt_p);
            } else if (c == '1') {
                // 逆时针
                int nxt_p = (p - 1 - r % n + n) % n + 1;
                nxt.insert(nxt_p);
            } else {
                // 方向未知，两个方向都可以
                int nxt_p1 = (p - 1 + r) % n + 1;
                int nxt_p2 = (p - 1 - r % n + n) % n + 1;
                nxt.insert(nxt_p1);
                nxt.insert(nxt_p2);
            }
        }
        // 更新当前集合
        cur = nxt;
    }

    // 输出结果
    cout << cur.size() << "\n";
    for (auto it = cur.begin(); it != cur.end(); ++it) {
        cout << *it << (next(it) == cur.end() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}