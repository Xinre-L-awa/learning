#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int m;
        long long x;
        cin >> m >> x;

        priority_queue<long long> pq;
        long long sum = 0;

        for (int i = 1; i <= m; ++i) {
            long long c;
            cin >> c;

            pq.push(c);
            sum += c;
            
            if (sum > 1LL * (i - 1) * x) {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << pq.size() << '\n';
    }

    return 0;
}