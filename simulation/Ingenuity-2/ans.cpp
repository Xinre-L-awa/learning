#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        string s;
        cin >> n >> s;

        map<char, int> cnt;
        for (int i = 0; i < n; i++) cnt[s[i]]++;

        if (abs(cnt['N'] - cnt['S']) % 2 == 1 || abs(cnt['E'] - cnt['W']) % 2 == 1) {
            cout << "NO\n";
            continue;
        } 

        map<char, int> h, r;
        bool f1 = true, f2 = true;
        if (cnt['N'] > cnt['S']) {
            int t = cnt['N'] - cnt['S'];
            h['N'] = t / 2 + cnt['S'];
            h['S'] = cnt['S'];
            r['N'] = t / 2;
            r['S'] = 0;
        } else if (cnt['N'] < cnt['S']){
            int t = cnt['S'] - cnt['N'];
            h['S'] = t / 2 + cnt['N'];
            h['N'] = cnt['N'];
            r['S'] = t / 2;
            r['N'] = 0;
        } else {
            h['N'] = cnt['N'];
            h['S'] = cnt['S'];
            r['N'] = 0;
            r['S'] = 0;
        }
        
        if (h['N'] >= 1 && h['S'] >= 1) {
            if (r['N'] == 0 && r['S'] == 0) {
                r['S']++; h['S']--;
                r['N']++; h['N']--;
            }
            f1 = true;
        } else if (r['N'] > 0 || r['S'] > 0) {
            f1 = true;
        } else {
            f1 = false;
        }

        if (cnt['E'] > cnt['W']) {
            int t = cnt['E'] - cnt['W'];
            h['E'] = t / 2 + cnt['W'];
            h['W'] = cnt['W'];
            r['E'] = t / 2;
            r['W'] = 0;
        } else if (cnt['E'] < cnt['W']){
            int t = cnt['W'] - cnt['E'];
            h['W'] = t / 2 + cnt['E'];
            h['E'] = cnt['E'];
            r['W'] = t / 2;
            r['E'] = 0;
        } else {
            h['E'] = cnt['E'];
            h['W'] = cnt['W'];
            r['E'] = 0;
            r['W'] = 0;
        }
        
        if (h['E'] >= 1 && h['W'] >= 1) {
            if (r['N'] == 0 && r['S'] == 0 && r['E'] == 0 && r['W'] == 0) {
                r['E']++; h['E']--;
                r['W']++; h['W']--;
            }
            f2 = true;
        } else if (r['E'] > 0 || r['W'] > 0) {
            f2 = true;
        } else {
            f2 = false;
        }

        if (!(f1 || f2)) {
            cout << "NO\n";
            continue;
        }

        string ans = "";
        int h_cnt = 0, r_cnt = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (h[ch] > 0) {
                ans += 'H';
                h[ch]--;
                h_cnt++;
            } else {
                ans += 'R';
                r_cnt++;
            }
        }

        if (h_cnt == 0 || r_cnt == 0) {
            cout << "NO\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}