#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    // 第一天填第 1 个坑需要的天数
    long long ans = d[0];
    
    // 从第 2 个坑开始遍历
    for (int i = 1; i < n; ++i) {
        // 如果当前坑比前一个坑深，需要额外花天数
        if (d[i] > d[i - 1]) {
            ans += d[i] - d[i - 1];
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}