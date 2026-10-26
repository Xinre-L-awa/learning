#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    // 记录可用字母，true 表示键盘上这个键没坏
    vector<bool> available(26, false);
    for (int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        available[c - 'a'] = true;
    }
    
    long long ans = 0; // 答案可能很大，必须用 long long
    long long len = 0;
    
    for (char c : s) {
        if (available[c - 'a']) {
            len++; // 当前字母可用，连续长度 +1
        } else {
            // 遇到坏键，结算上一段
            ans += len * (len + 1) / 2;
            len = 0; // 重置长度
        }
    }
    
    // 不要忘记处理字符串末尾的最后一段
    ans += len * (len + 1) / 2;
    
    cout << ans << "\n";
    return 0;
}