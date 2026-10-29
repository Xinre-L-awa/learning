#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Op {
    int d, type;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<Op> op;
        for (int i = 0; i < m; i++) {
            int d;
            char t;
            cin >> d >> t;
            if (t == '?') op.push_back({d, 2});
            else op.push_back({d, t - '0'});
        }
        sort(op.begin(), op.end(), [](const Op& a, const Op& b){
            return a.type < b.type;
        });

        
        vector<int> cur = {x};
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            vector<bool> is(n + 1, false);
            while (!cur.empty()) {
                int p = cur.back();

                if (op[i].type == 0) {
                    int p___ = (p + op[i].d - 1) % n + 1;
                    if (p___ == 0) p___ = n;
                    if (!is[p___]) {
                        tmp.push_back(p___);
                        is[p___] = true;
                    }
                } else if (op[i].type == 1) {
                    int p___ = (p + n - (op[i].d % n) - 1) % n + 1;
                    if (p___ == 0) p___ = n;

                    if (!is[p___]) {
                        tmp.push_back(p___);
                        is[p___] = true;
                    }
                } else {
                    int p___ = (p + op[i].d - 1) % n + 1;
                    if (p___ == 0) p___ = n;
                    if (!is[p___]) {
                        tmp.push_back(p___);
                        is[p___] = true;
                    }
                    p___ = (p + n - (op[i].d % n)) % n;
                    if (p___ == 0) p___ = n;

                    if (!is[p___]) {
                        tmp.push_back(p___);
                        is[p___] = true;
                    }
                }
                cur.pop_back();
            }

            cur = tmp;
        }

        sort(cur.begin(), cur.end());
        cout << (int)cur.size() << '\n';
        for (int& i : cur) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
