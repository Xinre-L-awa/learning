#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // 1. 排序
    sort(a.begin(), a.end());
    
    // mp[x] 存储以数字 x 结尾的所有组的长度（用小根堆维护）
    // 这样每次能快速取出长度最短的组
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    
    for (int x : a) {
        if (mp.count(x - 1) && !mp[x - 1].empty()) {
            // 找到了以 x-1 结尾的组，取出其中最短的
            int len = mp[x - 1].top();
            mp[x - 1].pop();
            
            // 把 x 接在这个组后面，组长度 +1，变为以 x 结尾
            mp[x].push(len + 1);
        } else {
            // 没有以 x-1 结尾的组，x 必须自己新开一个组
            mp[x].push(1);
        }
    }
    
    // 2. 统计所有组的最小长度
    int ans = INT_MAX;
    for (auto& [val, pq] : mp) {
        while (!pq.empty()) {
            ans = min(ans, pq.top());
            pq.pop();
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}