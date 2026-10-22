#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    if (n == 1) { cout << 1; return 0; }
    sort(p.begin(), p.end());
    
    int ans = 0;
    while ((int)p.size() > 1) {
        int r = w - p.back();
        if (r >= p[0]) {
            auto it = upper_bound(p.begin(), p.end() - 1, r) - 1;
            p.erase(it);        
        }
        
        ans++;
        p.pop_back();
    }

    if (!p.empty()) ans++;

    cout << ans;
    return 0;
}