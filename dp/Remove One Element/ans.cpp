#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> l(n, 0), r(n, 0);
    l[0] = 1;
    r[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
        else l[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) r[i] = r[i + 1] + 1;
        else r[i] = 1;
    }

    // 1. 先计算不删除任何元素时的最大长度
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, l[i]);
    }

    // 2. 枚举删除的元素 a[i] (只考虑中间的元素)
    for (int i = 1; i <= n - 2; i++) {
        if (a[i - 1] < a[i + 1]) {
            ans = max(ans, l[i - 1] + r[i + 1]);
        }
    }
    
    cout << ans;

    return 0;
}
