#include <bits/stdc++.h>
using namespace std;

struct Q { int u, v, p, id; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Q> qs(m);
    for (int i = 0; i < m; i++) {
        cin >> qs[i].u >> qs[i].v >> qs[i].p;
        if (qs[i].u > qs[i].v) swap(qs[i].u, qs[i].v);   // 保险，题面没保证 u<=v
        qs[i].id = i;
    }

    // 离线：按右端点排序，从左往右扫一遍
    sort(qs.begin(), qs.end(), [](const Q& x, const Q& y) { return x.v < y.v; });

    vector<int> last(1001, -1), ans(m, 0);
    int cur = -1;
    for (const Q& q : qs) {
        while (cur < q.v) { cur++; last[a[cur]] = cur; }  // last[val] = <=v 的最后位置

        // 余数从大到小枚举，第一个成立的就是答案
        for (int r = q.p - 1; r >= 1; r--) {
            bool found = false;
            for (int val = r; val <= 1000; val += q.p)
                if (last[val] >= q.u) { found = true; break; }   // O(1) 判断
            if (found) { ans[q.id] = r; break; }
        }
    }

    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
    return 0;
}