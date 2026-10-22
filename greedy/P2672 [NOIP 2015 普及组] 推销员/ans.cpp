/*
以为自己写出一道提高题了，实则拉了坨大的(((
*/




#include <bits/stdc++.h>
using namespace std;

struct obj {
    int i;
    int a;
    obj(int i, int a): i(i), a(a) {}
};

int main() {
    int n;
    cin >> n;
    vector<int> s(n + 1), a(n + 1), cost(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    long long ans = 0;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cost[i] = 2 * s[i] + a[i];
        if (cost[i] > ans || (cost[i] == ans && s[i] > s[idx])) {
            ans = cost[i];
            idx = i;
        }
    }

    vector<obj> p;
    for (int i = 1; i < idx; i++) {
        obj p_(i, a[i]);
        p.push_back(p_);
    }

    sort(p.begin(), p.end(), [](const obj& a, const obj& b){
        return a.a < b.a;
    });
    vector<long long> pref(max(0, idx - 1), 0);
    for (int k = 0; k < idx - 1; k++) {
        pref[k] = (k == 0 ? 0 : pref[k - 1]) + p[idx - 2 - k].a;
    }

    vector<long long> prefff(max(0, n - idx), 0);
    if (idx + 1 <= n) {
        vector<obj> ppp;
        for (int i = idx + 1; i <= n; i++) {
            obj p_(i, a[i]);
            ppp.push_back(p_);
        }
        sort(ppp.begin(), ppp.end(), [](const obj& a, const obj& b){
            return a.a < b.a;
        });

        int m = (int)ppp.size();
        for (int k = 0; k < m; k++) {
            prefff[k] = (k == 0 ? 0 : prefff[k - 1]) + ppp[m - 1 - k].a;
        }
    }

    int cur_r = idx;
    for (int x = 1; x <= n; x++) {
        if (x == 1) {
            printf("%lld\n", ans);
            continue;
        }

        if (x <= idx) {
            printf("%lld\n", ans + pref[x - 2]);
            if (x == idx) {
                ans += pref[idx - 2];
            }
            continue;
        }
        
        ans += 2LL * (s[cur_r + 1] - s[cur_r]) + prefff[x - idx - 1];
        cur_r++;
        printf("%lld\n", ans);
    }

    return 0;
}