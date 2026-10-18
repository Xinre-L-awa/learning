#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> order(m * n);
    for (int i = 0; i < m * n; i++)
        cin >> order[i];

    vector<vector<int>> machine(n + 1, vector<int>(m + 1));
    vector<vector<int>> time(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> machine[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> time[i][j];

    vector<int> step(n + 1, 0);
    vector<int> last_end(n + 1, 0);
    const int MAXT = 10005;
    vector<vector<bool>> busy(m + 1, vector<bool>(MAXT, false));
    
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        int j = order[i];          // 当前工件
        int k = ++step[j];         // 当前工序
        int dur = time[j][k];
        int ma = machine[j][k];    // 使用的机器

        int start = last_end[j];
        while (true) {
            bool ok = true;
            for (int t = start; t < start + dur; t++) {
                if (busy[ma][t]) {ok = false; break;}
            }
            if (ok) break;
            start++;
        }

        for (int t = start; t < start + dur; t++) {
            busy[ma][t] = true;
        }

        last_end[j] = start + dur;
        
        ans = max(ans, last_end[j]);
    }

    cout << ans;
    
    return 0;
}