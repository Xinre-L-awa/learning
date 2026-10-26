#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int cL = 0, cR = 0, cU = 0, cD = 0;
        for (char c : s) {
            if (c == 'L') cL++;
            else if (c == 'R') cR++;
            else if (c == 'U') cU++;
            else if (c == 'D') cD++;
        }

        int l = min(cL, cR);
        int u = min(cU, cD);

        if (l > 0 && u > 0) {
            cout << 2 * l + 2 * u << '\n';
            cout << string(l, 'L') << string(u, 'U') << string(l, 'R') << string(u, 'D') << '\n';
        } else if (l > 0) {
            cout << 2 << '\n';
            cout << "LR" << '\n';
        } else if (u > 0) {
            cout << 2 << '\n';
            cout << "UD" << '\n';
        }
        else {
            cout << 0 << '\n';
            cout << '\n';
        }
    }
    return 0;
}