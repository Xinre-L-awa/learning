// 此题解为 O(n log n) 解法
// 与 ans O(n^2).cpp 同一题：求字符串 s 的最长不下降子序列长度（允许 s[j] == s[i]）

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;      // 长度
    string s;   // 字符串
    cin >> n >> s;

    // tails[k] 表示"长度为 k+1 的不下降子序列"的结尾字符的最小值
    // 这个数组天然单调不降，因此可以二分
    vector<char> tails;

    for (char ch : s) {
        // 不下降允许相等，所以找第一个严格大于 ch 的位置替换
        // （若求严格上升子序列，这里应改用 lower_bound）
        auto it = upper_bound(tails.begin(), tails.end(), ch);
        if (it == tails.end()) tails.push_back(ch);
        else *it = ch;
    }

    cout << tails.size();

    return 0;
}
