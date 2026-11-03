# Computer Game 题解

## 题意

首行是测试用例个数（`ans.cpp` 里叫 `t`，`ans_math.cpp` 里叫 `q`）。每个测试用例按代码的读入顺序给出四个整数 $k,n,a,b$：一共要打 $n$ 回合，每回合从两种消耗里选一种——耗 $a$ 点或耗 $b$ 点。设选了耗 $a$ 的回合有 $x$ 个，则耗 $b$ 的回合有 $n-x$ 个。

整个过程不能中途见底，而代码把这件事写成了一句关于总消耗的约束：

$$x\cdot a+(n-x)\cdot b\le k-1$$

即总消耗严格小于 $k$。在满足它的前提下让 $x$ 尽量大并输出；若连 $x=0$ 都做不到，输出 $-1$。

由 [ans_math.cpp](<binary_search/Computer Game/ans_math.cpp>) 中直接以 $a-b$ 作除数可以推断：题目保证 $a>b$。

## 思路

### 一、$n$ 个回合的约束为什么能压成一个不等式

设第 $i$ 回合的消耗为 $c_i\in\{a,b\}$。要求是「每回合打完之后仍有剩余」，也就是对每个 $i$ 都成立

$$k-\sum_{j=1}^{i}c_j>0\quad\Longleftrightarrow\quad \sum_{j=1}^{i}c_j\le k-1$$

这 $n$ 条条件里真正卡人的，是「前缀和最大」的那一条。每次消耗都是正数，而两类回合的先后顺序由我们自己安排：把更便宜的 $b$ 型回合全部排在前面，前缀和就单调递增，最大值恰好落在最后一回合，也就是

$$\sum_{j=1}^{n}c_j=x\cdot a+(n-x)\cdot b\quad(\text{记为 }D(x))$$

于是 $n$ 条前缀条件被压缩成一条 $D(x)\le k-1$。它必要（$D(x)\ge k$ 时最后一回合结束时剩余 $\le 0$），也充分（按 $b$ 在前、$a$ 在后的顺序排列，任何前缀都不超过 $D(x)$）。这就是两份代码共用的唯一判据，也正是上文「题意」里那句「总消耗严格小于 $k$」的来历：它不是近似，而是把 $n$ 条逐步约束等价合并的结果。

### 二、单调性：$x$ 越大越费

$$D(x)=x\cdot a+(n-x)\cdot b=n\cdot b+x\cdot(a-b)$$

因为 $a>b$，$D(x)$ 关于 $x$ 严格递增。所以「$D(x)\le k-1$」对较小的 $x$ 成立、对较大的 $x$ 不成立，可行集合是一个前缀区间 $[0,x^\ast]$，可以放心二分。[ans.cpp](<binary_search/Computer Game/ans.cpp>) 正是在 $[0,n]$ 上二分出最大的合法 $x$。

### 三、为什么 $k\le n\cdot b$ 时输出 $-1$

$x$ 越小越省，最省的极端是 $x=0$：$n$ 个回合全部耗 $b$，总消耗 $n\cdot b$。若 $n\cdot b\ge k$，连这个最省方案都过不了 $D(0)\le k-1$，可行集合为空，只能输出 $-1$。

$$x=0\text{ 可行}\iff n\cdot b\le k-1\iff n\cdot b<k$$

注意等号也必须归入 $-1$：$n\cdot b=k$ 意味着最后一回合刚好吃到 $0$，而约束是严格不等式，同样不合法。这解释了为什么两份代码都写 `k <= n*b` / `n*b >= k`，而不是 `<`。

### 四、公式法：两个上界各自代表什么

把 $D(x)\le k-1$ 当作一元一次不等式解出来：

$$x\cdot(a-b)\le k-1-n\cdot b\ \Longrightarrow\ x\le\left\lfloor\frac{k-1-n\cdot b}{a-b}\right\rfloor$$

记作 `max_x1`，它是**总量上界**：$x$ 再多，总消耗就超了 $k-1$。由于 $-1$ 分支已提前保证 $k-1-n\cdot b\ge 0$，分子非负，C++ 的整数除法正好就是向下取整，可以照直写。

第二个上界来自另一个角度——「中途也不能见底」：任何前缀里只要出现了 $y$ 个 $a$ 型回合，这段前缀的消耗就至少是 $y\cdot a$（其余回合还要各耗 $b>0$），而前缀消耗必须 $\le k-1$，所以 $y\le\lfloor (k-1)/a\rfloor$——**不需要**这些 $a$ 型回合连续，把整个游戏（$y=x$）代进去即得

$$x\le\left\lfloor\frac{k-1}{a}\right\rfloor$$

记作 `max_x2`。代码里写成 `(k + a - 1) / a - 1`，即 $\lceil k/a\rceil-1$。

再加上 $n$ 这个显然的上界（不能超过回合总数），三个都是必要条件，同时满足它们的最大 $x$ 就是答案：

$$\text{ans}=\min\{n,\ \text{max\_x1},\ \text{max\_x2}\}$$

取 $\min$ 不是随手保险，而是因为三条约束分别来自不同层面：总数不能超 $n$、总量不能超 $k-1$、中途前缀不能超 $k-1$。可行集合对每条都是「$\le$ 某个上界」，交集自然也是「$\le$ 三者中最小的那个」，而截断后的最大值正是这个最小值。

补充一点：既然顺序可以自由排列，`max_x2` 其实已被 `max_x1` 蕴含——当 $a>b$ 且 $k>n\cdot b$ 时可以验证 $\min(n,\text{max\_x1},\text{max\_x2})=\min(n,\text{max\_x1})$（要么 $\text{max\_x2}\ge n$ 而被 $n$ 截掉，要么 $\text{max\_x2}\ge\text{max\_x1}$ 而被它截掉）。作者显式写出 `max_x2`，是把「过程不能为 $0$」这条独立的安全条件摆到明面上；多一个冗余上界取 $\min$，不会让答案变小。

### 五、作者注释里那个等价关系

注释在纠结 `(k + a - 1) / a - 1` 与 `(k - 1) / a`，结论是「直接用 `(k-1)/a` 也没问题」。更准确的说法是：这两个表达式在整数运算下**恒等**，不是近似，也不是「略有冗余」的近似写法。设 $k=qa+r$，$0\le r<a$：

- $r=0$：$\lceil k/a\rceil-1=q-1$，而 $\lfloor(k-1)/a\rfloor=\lfloor(qa-1)/a\rfloor=q-1$；
- $r>0$：$\lceil k/a\rceil-1=q$，而 $\lfloor(k-1)/a\rfloor=\lfloor(qa+r-1)/a\rfloor=q$（此时 $0\le r-1<a$）。

所以对任意正整数 $k,a$ 都有

$$\left\lceil\frac{k}{a}\right\rceil-1=\left\lfloor\frac{k-1}{a}\right\rfloor$$

两种写法都等于「最大的满足 $x\cdot a<k$（即 $x\cdot a\le k-1$）的 $x$」。注释里那处措辞不算精确，但写法本身是对的，不影响结果。

## 复杂度

- [ans.cpp](<binary_search/Computer Game/ans.cpp>)：每个测试用例二分 $O(\log n)$ 次，总计 $O(t\log n)$，额外空间 $O(1)$。
- [ans_math.cpp](<binary_search/Computer Game/ans_math.cpp>)：每个测试用例 $O(1)$，总计 $O(q)$，额外空间 $O(1)$。

两份代码都把 $k,n,a,b$ 与乘积交给 `long long`，说明乘积可能超出 32 位整数；照抄时不要为省事换成 `int`。

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
        ll k, n, a, b;
        cin >> k >> n >> a >> b;

        // 全选 b 型回合是最省的方案，若它都不行则无解
        if (k <= n * b) {
            cout << -1 << '\n';
            continue;
        }

        // 二分最大的 x，使 x*a + (n-x)*b <= k-1
        ll l = 0, r = n, ans = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (mid * a + (n - mid) * b <= k - 1) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

## 易错点

1. **不等号要严格**：判据是 $D(x)\le k-1$，不是 $\le k$。写成 `mid * a + (n - mid) * b <= k` 时，凡是满足 $D(x)=k$ 的 $x$ 都会被误判成可行（最后一回合刚好把电量打光），例如 $k=7,n=5,a=3,b=1$：正确输出 $0$，写成 $\le k$ 会输出 $1$。至于 `n*b = k` 这种情形根本进不了二分，它已经被前面的 $-1$ 分支截走。
2. **$-1$ 的判据别漏等号**：`k <= n * b`（等价 `n * b >= k`）。少一个等号会把「最后一回合刚好耗尽」算成有解。
3. **别把「中途」和「总量」混成一条直觉**：误以为 $x$ 个 $a$ 型回合必须连续，就会只盯 `max_x2` 而漏掉总量约束；反过来，只报「总量 $D(x)\le k-1$」却不解释它为什么已经覆盖了「中途不能见底」，也少了一步论证——每回合消耗都是正数，任何前缀都不超过总和，把 $b$ 型回合排在前面时前缀更是最小。
4. **`(a-b)` 当除数**：公式法依赖 $a>b$。$a=b$ 会除零，$a<b$ 则不等式方向翻转、`max_x1` 直接算错——这也是参考代码选二分版本的原因：二分在 $a=b$ 时仍然给出正确答案。
5. **溢出**：`mid * a`、`n * b`、`k - 1 - n * b` 都可能很大，全程用 `long long`。
6. **二分边界**：`l = 0, r = n, ans = 0`；由于 $-1$ 分支已保证 $x=0$ 可行，`ans` 一定会被赋值，不会输出初值脏数据。
7. **读入顺序**：四个数固定是 $k,n,a,b$（电量在前、回合数次之），与别处常见的 `n,k` 顺序不同，调换会把两者搞反。

## 总结

两步走：先用「$b$ 型回合排前面」把 $n$ 条逐步约束等价压成一条总消耗不等式 $D(x)=n\cdot b+x\,(a-b)\le k-1$，再利用 $a>b$ 带来的单调性求解。二分是 $O(\log n)$ 的通解、对 $a=b$ 也安全；公式法是 $O(1)$，但要多加 $n$ 的截断并使用 $\min$，且必须 $a>b$。

## 说明

文件夹名是 Computer Game，代码本身不含题面，上面的题意是按两份代码的行为（四个数 $k,n,a,b$、总消耗 $\le k-1$、$-1$ 条件）反推的；若与记忆中的原题面有出入，以代码为准。两份代码在 $a>b$ 时结果一致，可以互相印证；[ans_math.cpp](<binary_search/Computer Game/ans_math.cpp>) 的注释把 $\lceil k/a\rceil-1$ 与 $\lfloor(k-1)/a\rfloor$ 说成「略有冗余」，实际二者同值，只是措辞不严谨，不影响正确性。
