#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        int x, y, z;
        cin >> x >> y >> z;

        // 针对每一种出拳，至少准备一半的克星（向上取整）
        int p_cnt = (x + 1) / 2; // 克制石头(R)用布(P)
        int r_cnt = (y + 1) / 2; // 克制剪刀(S)用石头(R)
        int s_cnt = (z + 1) / 2; // 克制布(P)用剪刀(S)

        // 计算还有多少回合没分配
        int rem = x + y + z - p_cnt - r_cnt - s_cnt;

        string ans = "";
        ans += string(p_cnt, 'P');
        ans += string(r_cnt, 'R');
        ans += string(s_cnt, 'S');
        
        // 剩下的回合随便填什么都可以（这里全填 R，填 P 或 S 也一样能过）
        ans += string(rem, 'R');

        cout << ans << '\n';
    }
    return 0;
}