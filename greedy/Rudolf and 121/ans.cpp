#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t-- > 0) {
        int n;
        cin >> n;
        vector<ll> a(n);

        bool ok = true;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i]) flag = true;
        }

        if (!flag) {
            cout << "YES\n";
            continue;
        }
        
        for (int i = 1; i < n - 1; i++) {
            if (a[i - 1] < 0) {
                ok = false;
                break;
            }

            if (a[i - 1] > 0) {
                ll val = a[i - 1];
                a[i + 1] -= val;
                a[i] -= 2 * val;
                a[i - 1] = 0;
            }
            
        }

        for (int i = 0; i < n; i++) if (a[i] != 0) ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }


    return 0;
}