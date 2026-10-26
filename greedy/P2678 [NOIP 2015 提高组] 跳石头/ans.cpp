#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, N, M;
    cin >> L >> N >> M;
    
    // dis 存储起点到各石头的距离
    vector<int> dis(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> dis[i];
    }
    // 把终点也当作一块石头，方便统一处理
    dis[N] = L;
    
    // 二分答案，范围 [1, L]
    int left = 1, right = L;
    int ans = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int cnt = 0;      // 记录移走的石头数量
        int last = 0;     // 记录上一次落脚的石头位置（起点）
        
        // 遍历每一块石头（包括终点）
        for (int i = 0; i <= N; ++i) {
            // 如果当前石头到上次落脚点的距离小于 mid，必须移走
            if (dis[i] - last < mid) {
                cnt++;
            } else {
                // 否则可以落脚，更新落脚点
                last = dis[i];
            }
        }
        
        // 如果移走的石头数 <= M，说明该 mid 可行
        if (cnt <= M) {
            ans = mid;      // 记录当前可行答案
            left = mid + 1; // 尝试更大的距离
        } else {
            right = mid - 1; // mid 太大，缩小范围
        }
    }
    
    cout << ans << "\n";
    return 0;
}