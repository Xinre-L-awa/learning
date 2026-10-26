#include <bits/stdc++.h>
using namespace std;

struct T {
    int s, l;
};

int main() {
    int n;
    cin >> n;
    
    vector<T> ts;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        T t;
        t.s = l;
        t.l = r - l;
        ts.push_back(t);
    }

    if (n == 1) {
        cout << ts[0].l << ' ' << 0;
        return 0;
    }

    // 【改1】按开始时刻 s 升序排，而不是按长度降序
    sort(ts.begin(), ts.end(), [](const T& a, const T& b){
        return a.s < b.s;
    });

    int ans1 = 0, ans2 = 0;
    int t1 = 0, s = 0; // t1 为当前区间长度
    for (int i = 0; i < n; ) {
        if (t1 == 0) {
            t1 = ts[i].l;
            s = ts[i].s; // 当前起始位置
        }

        int j = i + 1;
        while (j < n && ts[j].s <= s + t1) {
            if (ts[j].l + ts[j].s > t1 + s) {
                t1 += ts[j].l + ts[j].s - (t1 + s);
            }
            j++;
        }
        ans1 = max(ans1, t1);
        
        if (j < n) {
            ans2 = max(ans2, ts[j].s - (t1 + s));
        }
        t1 = 0;
        i = j;
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}