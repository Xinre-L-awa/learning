#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(n), b(m), c(k), d(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < k; i++) cin >> c[i];
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        for (int i = 0; i < n - 1; i++) d[i] = a[i + 1] - a[i];

        // 查找最大差值的位置        
        ll max_diff = 0;
        int idx = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (d[i] > max_diff) {
                max_diff = d[i];
                idx = i;
                cnt = 1;
            } else if (d[i] == max_diff) {
                cnt++;
            }
        }

        // 如果最大差值出现多次，插入一个数无法消除所有最大差值，答案就是最大差值本身
        if (cnt > 1) {
            cout << max_diff << '\n';
            continue;
        }

        // 查找第二大差值
        int d2 = 0;
        for (int i = 0; i < n - 1; i++) 
            if (d[i] > d2 && d[i] < d[idx]) d2 = d[i];
        // if (d2 == 0) d2 = d[idx];

        ll ans = d[idx];
        //cout << "idx = " << idx << endl;
        bool flag = true;
        for (int i = 0; i < m && flag; i++) {
            auto it = lower_bound(c.begin(), c.end(), a[idx] - b[i]);

            //cout << "aidx - bi = " << a[idx] - b[i] << endl;
            if (it != c.end() && *it + b[i] < a[idx + 1]) {
                for (; it != c.end() && *it + b[i] < a[idx + 1]; it++) {
                    ll t1 = b[i] + *it - a[idx], t2 = d[idx] - t1;
                    if (t1 > t2) swap(t1, t2);

                    //cout << t1 << ' ' << t2 << endl;

                    if (t2 < ans) {
                        if (t2 < d2) {
                            ans = d2;
                            flag = false;
                            break;
                        } else {
                            ans = t2;
                        }
                    }

                    if (t1 + 1 == t2 || t1 == t2) {
                        flag = false;
                        break;
                    }
                }
            } else if (it == c.end()) break;
        }

        cout << ans << '\n';
    }

    return 0;
}