#include <bits/stdc++.h>
using namespace std;

struct P {
    int i, f;   // 时刻 i，事件 f（+1 开始，-1 结束）
};

int main() {
    int n;
    cin >> n;

    vector<P> ps;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ps.push_back({l, 1});
        ps.push_back({r, -1});
    }

    // 同一时刻：+1 先于 -1，避免把"瞬间"误算成空闲
    sort(ps.begin(), ps.end(), [](const P& a, const P& b){
        if (a.i != b.i) return a.i < b.i;
        return a.f > b.f;          // +1 在前
    });

    int ans1 = 0, ans2 = 0;
    int cnt = 0;                   // 当前正在挤奶的人数
    int start = -1;                // 当前"挤奶段"的起点
    int last = ps[0].i;            // 上一个事件时刻

    for (int k = 0; k < (int)ps.size(); k++) {
        int cur = ps[k].i;

        // 用 [last, cur] 这段的 cnt 状态结算
        if (cnt > 0) {
            // 这段时间有人在挤奶
            ans1 = max(ans1, cur - last);
        } else if (start != -1) {
            // 曾经开始过挤奶，现在空闲
            ans2 = max(ans2, cur - last);
        }

        // 处理同一时刻的多个事件：先全部加/减完再算下一段
        // 这里逐个处理，但由于 +1 排在 -1 前，
        // 同一时刻 cnt 会先增后减，不会出现"瞬时 0"被误判
        cnt += ps[k].f;
        if (cnt > 0 && start == -1) start = cur;   // 记录第一次开始的时刻
        last = cur;
    }

    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}