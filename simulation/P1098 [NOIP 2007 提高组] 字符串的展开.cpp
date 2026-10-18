#include <bits/stdc++.h>
using namespace std;

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;

    vector<string> r;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '-') {
            bool both_digit = isdigit(s[i-1]) && isdigit(s[i+1]);
            bool both_alpha = isalpha(s[i-1]) && isalpha(s[i+1]);
            bool ok = (both_digit || both_alpha);
            if (!ok) {
                r.push_back("-");
                continue;
            }
            
            string t = "";
            int l = s[i + 1] - s[i - 1] - 1;
            if (l == 0) {
                r.push_back("");
                continue;
            }
            for (int j = 1; j <= l; j++) {
                // 先计算要填充的字符
                char ch;
                if (isalpha(s[i - 1])) {
                    if (p1 == 1) {
                        ch = s[i - 1] + (p3 == 1 ? j : l - j + 1);
                    } else if (p1 == 2) {
                        ch = s[i - 1] + (p3 == 1 ? j : l - j + 1) - 32;
                    } else ch = '*';
                } else {
                    if (p1 == 3) ch = '*';
                    else ch = s[i - 1] + (p3 == 1 ? j : l - j + 1);
                }

                // 生成字符串
                for (int k = 1; k <= p2; k++) t += ch;
            }

            r.push_back(t == "" ? "-" : t);
        }
    }

    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            cout << r[idx++];
        } else {
            cout << s[i];
        }
    }

    return 0;
}