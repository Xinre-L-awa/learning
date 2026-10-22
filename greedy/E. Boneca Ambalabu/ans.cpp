#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(31, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            
            for (int j = 0; j < 30; j++)
                if (a[i] & (1 << j)) cnt[j]++;
        }

        long long ans = 0ll;
        for (int k = 0; k < n; k++) {
            long long sum = 0ll;
            for (int j = 0; j < 30; j++) {
                int t = 1 << j;
                if (a[k] & t) sum += (n - cnt[j]) * t;
                else sum += cnt[j] * t;
            }
            ans = max(ans, sum);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
