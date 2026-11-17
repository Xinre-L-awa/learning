#include <iostream>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    
    // 计算原区间所有数字之和
    long long sum = (long long)(l + r) * (r - l + 1) / 2;
    
    // 枚举 k 从 1 到区间数字总个数
    for (int k = 1; k <= r - l + 1; ++k) {
        // 选 k 个数的最小和
        long long min_sum = (long long)k * l + (long long)k * (k - 1) / 2;
        // 选 k 个数的最大和
        long long max_sum = (long long)k * r - (long long)k * (k - 1) / 2;
        
        // 如果总和在这个范围内，说明可以选出 k 个数凑成总和
        if (min_sum <= sum && sum <= max_sum) {
            cout << k - 1 << "\n";
            return;
        }
    }
}

int main() {
    // 优化输入输出流
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}