#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) ans = b - a;
        else if (abs(a) == b) ans = 0;
        else if (a == 0 || b == 0) {
            ans = (b - a) - 1;
        }
        else {
            if (abs(a) > b) {
                ans = abs(a) - b - 1;
            } else {
                ans = b - abs(a) - 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}