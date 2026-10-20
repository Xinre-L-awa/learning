// https://www.luogu.com.cn/problem/P2249

#include <bits/stdc++.h>
using namespace std;

int bs(const vector<int>& a, int val) {
    int l = 0, r = (int)a.size() - 1, ans = -1;
    int mid = (l + r) / 2;
    while (l <= r) {
        if (a[mid] == val) {
            r = mid - 1;
            ans = mid + 1;
        }
        else if (a[mid] < val) l = mid + 1;
        else r = mid - 1;

        mid = (l + r) / 2;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;
        cout << bs(a, v) << ' ';
    }
    
    return 0;
}