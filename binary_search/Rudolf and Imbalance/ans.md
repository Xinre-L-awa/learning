# Rudolf and Imbalance 题解

## 题意

给定 $t$ 组数据。每组给出 $n,m,k$ 与三个数组：$a$（代码没有对 $a$ 排序，可见题目保证它已递增有序）、长度为 $m$ 的 $b$、长度为 $k$ 的 $c$。允许进行至多一次操作：选出 $(i,j)$，把 $b_i+c_j$ 插入 $a$ 的任意位置，使插入后相邻元素之差的最大值尽量小，输出这个最小值。

"至多一次"意味着"不插"本身就是合法候选，所以代码把答案初值取成原最大差 $M$，之后只往下调。这里不能改读成"必须插一次"：落点在 $[a_1,a_n]$ 之外可能把最大差撑得更大；落在某个已有区间内部则只是把它劈成两段更小的差，最大值不变大。

## 思路

**(1) 最大差出现多次时直接收尾。** 记 $d_i=a_{i+1}-a_i$，先求 $M=\max d_i$ 及其出现次数。一次插入只作用在一个区间上，把 $M$ 所在的一段劈开后，其它同样等于 $M$ 的段原封不动，最大值仍是 $M$。所以只要计数 $\ge 2$，答案就是 $M$，枚举下去也不可能更小。

**(2) 唯一最大差时，答案的形状。** 设最大差唯一地出现在 $[L,R]=[a_{idx},a_{idx+1}]$，其余区间的最大差记为 $d_2$。插入 $v\in[L,R]$ 后，差值集合变成 $\{d_i\mid i\ne idx\}\cup\{v-L,\;R-v\}$，于是

$$\text{ans}=\max\bigl(d_2,\;v-L,\;R-v\bigr).$$

$d_2$ 必须留在式子里：劈开最大段并不能消除次大段。而如果 $v$ 没落进 $(L,R)$，最大值不会低于 $M$（插到数组两端之外甚至更大），所以 $ans$ 的初值就取 $M$，之后只会单调变小。

**(3) 每个 $b_i$ 只需要两个候选。** 固定 $b_i$，令 $v=b_i+c_j$。函数 $f(v)=\max(v-L,\,R-v)$ 在 $[L,R]$ 上是 V 形的：以 $(L+R)/2$ 为谷底，先降后升。因此 $c_j$ 越靠近 $\mathit{tgt}=(L+R)/2-b_i$ 越好。$c$ 已排序，一次 `lower_bound` 就定位到第一个 $\ge\mathit{tgt}$ 的位置，它和它前面那个元素是唯一可能最优的两侧候选，再往外的点离谷底只会更远。

整数除法会把 $\mathit{tgt}$ 下取整，但 $f$ 在谷底两侧各单调：$v$ 小于 $(L+R)/2$ 时越小越差，大于时越大越差。紧邻 $\mathit{tgt}$ 两侧的这两个候选分别在各自一侧最优，所以下取整不影响结果。

**(4) 用区间检查代替"谁更优"。** 只有 $v\in[L,R]$ 时才更新答案，其它位置只会把数插进别的区间或数组两端之外，最大差不可能低于 $M$，直接跳过即可，不需要和数组元素逐个比较。

## 复杂度

排序 $O(m\log m+k\log k)$，求差与次大差 $O(n)$，$m$ 次 `lower_bound` 共 $O(m\log k)$，单组总复杂度

$$O\bigl(n+m\log m+k\log k+m\log k\bigr),$$

各组按规模累加；空间 $O(n+m+k)$。相比之下，wrong.cpp 在每个 $b_i$ 上把窗口内的 $c$ 逐个扫描，最坏 $O(mk)$。

## 参考代码（C++17）

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(n), b(m), c(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < k; i++) cin >> c[i];
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        vector<ll> d(n - 1);
        for (int i = 0; i < n - 1; i++) d[i] = a[i + 1] - a[i];

        // 最大差、其位置与出现次数
        ll max_diff = 0;
        int idx = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (d[i] > max_diff) {
                max_diff = d[i];
                idx = i;
                cnt = 1;
            } else if (d[i] == max_diff) {
                cnt++;
            }
        }
        if (cnt > 1) {                 // 一次插入消不掉所有最大差
            cout << max_diff << '\n';
            continue;
        }

        // 次大差：劈开最大段后它仍然存在
        ll d2 = 0;
        for (int i = 0; i < n - 1; i++)
            if (i != idx) d2 = max(d2, d[i]);

        ll ans = max_diff;
        ll L = a[idx], R = a[idx + 1];

        for (int i = 0; i < m; i++) {
            ll tgt = (L + R) / 2 - b[i];        // 希望落点尽量靠近中点
            auto it = lower_bound(c.begin(), c.end(), tgt);

            if (it != c.end()) {                // 中点右侧的候选
                ll val = b[i] + *it;
                if (val >= L && val <= R)
                    ans = min(ans, max({d2, val - L, R - val}));
            }
            if (it != c.begin()) {              // 中点左侧的候选
                auto it2 = prev(it);
                ll val = b[i] + *it2;
                if (val >= L && val <= R)
                    ans = min(ans, max({d2, val - L, R - val}));
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
```

## 易错点

- **最大差出现多次时不要再枚举。** 计数 $\ge 2$ 就直接输出 $M$，继续找插入位置只是白做，答案不可能更小。
- **别漏掉次大差 $d_2$。** 只比较 $v-L$ 与 $R-v$ 会把答案算小；正确值是 $\max(d_2,v-L,R-v)$，代码用 `max({d2, val - L, R - val})` 一次取完。
- **`lower_bound` 的两个边界都要判。** `it == c.begin()` 时没有前驱，不能 `prev`；`it == c.end()` 时"前驱"是 $c$ 的最后一个元素，恰恰是唯一可能更优的下侧候选。正解的 `if (it != c.end())` 与 `if (it != c.begin())` 正好覆盖这两种情况，缺一个就会漏候选或越界。
- **只取 `*it` 不够。** 目标值左侧的那个元素同样可能是最优解。
- **全程 `long long`。** 单看 $b_i+c_j$ 与相邻差，量级已经顶到 `int` 上限附近，而 $(L+R)$ 这样的中间量会直接溢出 `int`；正解从 $a,b,c$ 到 $d,ans$ 一律用 `long long`，省掉这类判断。

### wrong.cpp 错在哪

1. **`else if (it == c.end()) break;` 直接跳出整个 $b$ 循环，这是致命的一处。** 当某个 $b_i$ 太小、连 $b_i+\max c$ 都够不到 $L$ 时，代码不再看后面更大的 $b$。反例：$n=2,m=2,k=1$，$a=[10,20]$，$b=[1,11]$，$c=[1]$。$b_0=1$ 时 `lower_bound` 找不到 $\ge 10-1=9$ 的 $c$，于是 `it == c.end()` 触发 `break`，输出 $10$；而取 $b_1+c_0=12$ 能把区间劈成 $2$ 与 $8$，答案是 $8$。这里应当写 `continue`，或者干脆不特判。
2. **单向下界扫描、全窗口遍历，丢掉正解的剪枝。** 它从 $L-b_i$ 的下界开始把窗口内所有 $c$ 扫一遍；这样虽然没在窗口内漏候选，但最坏 $O(mk)$。`t1+1==t2` 与 `t2<d2` 两处提前退出能让常见数据很快结束，可那是运气而非保证。
3. **`*it + b[i] < a[idx+1]` 写成严格小于。** 恰好等于 $R$ 的候选被挡在门外。单看这一条其实不会算错（插入 $R$ 会把最大差原样保留，不可能更优），真正的坑是它和上一条写在同一个 `if` 里，令人以为边界已经处理干净。
4. **`int d2` 与 `long long d[]` 混用。** 本题数据下差值刚好还没越过 `int`，所以它不一定真出错；但把 `long long` 往 `int` 里塞属于隐患，正解里 $d_2$ 同样是 `long long`。

## 总结

正解把问题拆成两层：先用"最大差是否唯一"判断还能不能改善，再用 V 形性质把每个 $b_i$ 的搜索压缩到 `lower_bound` 的两个邻居，最后与次大差取 $\max$ 得到该候选下的答案。wrong.cpp 的分情况判断与正解一致，坏在枚举阶段：一次越界的 `break` 直接丢掉了后半部分 $b$，全窗口扫描又让复杂度退化到 $O(mk)$。
