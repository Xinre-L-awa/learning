#include <bits/stdc++.h>
using namespace std;

struct P {
    int v[504];
    int idx;
    P(int idx): v{}, idx(idx) {}
    void set(int i, int val) {
        v[i] = val;
    }
};

int main() {
    int n;
    cin >> n;
    vector<P> h;
    h.reserve(n);
    for (int i = 1; i <= n; i++) {
        P p(i);
        for (int j = i + 1; j <= n; j++) {
            int v; cin >> v;
            p.set(j, v);
        }
        for (int j = 0; j < i; j++) {
            p.set(j + 1, h[j].v[i]);
        }
        h.push_back(p);
    }

    int ans = 0;
    for (auto& p : h) {
        sort(p.v + 1, p.v + n + 1);
        ans = max(p.v[n - 1], ans);
    }
    cout << 1 << '\n';
    cout << ans;

    return 0;
}