#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    // 6 种合法的完美循环模板
    vector<string> patterns = {"abc", "acb", "bac", "bca", "cab", "cba"};
    
    // pre[6][n+1] 记录前缀差异
    // pre[p][i] 表示前 i 个字符中，原串与第 p 个模板不同的字符数
    vector<vector<int>> pre(6, vector<int>(n + 1, 0));

    for (int p = 0; p < 6; p++) {
        for (int i = 0; i < n; i++) {
            // 判断原串第 i 个字符与模板第 i 个字符是否相同
            // 模板是循环的，所以取模 3
            int diff = (s[i] != patterns[p][i % 3]) ? 1 : 0;
            pre[p][i + 1] = pre[p][i] + diff;
        }
    }

    // 处理查询
    while (m--) {
        int l, r;
        cin >> l >> r;
        // 题目是 1-indexed，转换为数组的 0-indexed
        // 区间 [l, r] 对应的前缀和差分是 pre[p][r] - pre[p][l-1]
        
        int ans = 1e9; // 初始化为无穷大
        for (int p = 0; p < 6; p++) {
            int cost = pre[p][r] - pre[p][l - 1];
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }

    return 0;
}