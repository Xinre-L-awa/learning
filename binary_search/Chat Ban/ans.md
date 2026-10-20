# D. Chat Ban 题解

## 题意

你要发送一个大小为 \(k\) 的表情三角形，共 \(2k-1\) 条消息，每条消息包含的表情数量依次为：

\[
1,2,\dots,k,k-1,k-2,\dots,1
\]

当累计发送的表情数 **至少达到 \(x\)** 时，你会被封禁。被封禁时正在发送的那条消息也计入消息数。问：你会发送多少条消息后封禁？如果发完整个三角形累计表情数仍然小于 \(x\)，则输出 \(2k-1\)。

注意总表情数为：

\[
1+2+\dots+k+(k-1)+\dots+1=k^2
\]

## 思路

如果 \(x>k^2\)，说明即使全部发完也不会被封禁，答案为 \(2k-1\)。

否则，需要找到最小的消息编号 \(m\)，使得前 \(m\) 条消息累计表情数 \(\ge x\)。

设前 \(m\) 条消息累计表情数为 \(f(m)\)：

- 当 \(m\le k\) 时：

\[
f(m)=\frac{m(m+1)}{2}
\]

- 当 \(m>k\) 时，令 \(r=m-k\)，则：

\[
f(m)=\frac{k(k+1)}{2}+r\cdot k-\frac{r(r+1)}{2}
\]

由于 \(f(m)\) 随 \(m\) 单调递增，可以二分答案 \(m\in[1,2k-1]\)。

## 复杂度

每个测试用例二分 \(O(\log k)\)，共 \(t\le10^4\)，完全可行。

## 参考代码（C++17）

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, x;

ll calc(ll m) {
    if (m <= k) {
        return m * (m + 1) / 2;
    }
    ll r = m - k;
    return k * (k + 1) / 2 + r * k - r * (r + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> k >> x;

        // 全部发完也不会被封禁
        if (x > k * k) {
            cout << 2 * k - 1 << '\n';
            continue;
        }

        ll lo = 1, hi = 2 * k - 1;
        ll ans = hi;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (calc(mid) >= x) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}