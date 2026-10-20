#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    cin >> a >> b >> c >> d;
    
    int cnt = 0;
    // 先检查 -100 是否是根
    if (fabs(f(-100)) < 1e-6) {
        printf("%.2f ", -100.0);
        cnt++;
    }
    
    for (int i = -100; i <= 99 && cnt < 3; i++) {
        double x1 = i, x2 = i + 1;
        double f1 = f(x1), f2 = f(x2);
        
        // 如果右端点是根
        if (fabs(f2) < 1e-6) {
            printf("%.2f ", x2);
            cnt++;
            // 因为根间距 >= 1，下一个根肯定不在 i+2 之前
            // 但循环会 i++，所以下次是 i+2。没问题。
            // 不过，如果 i+1 是根，那么 (i, i+1) 之间不可能有根，所以不用二分。
            continue;
        }
        
        // 如果区间内有根
        if (f1 * f2 < 0) {
            double l = x1, r = x2;
            for (int k = 0; k < 100; k++) {
                double mid = (l + r) / 2;
                if (f(l) * f(mid) <= 0) r = mid;
                else l = mid;
            }
            printf("%.2f ", l);
            cnt++;
        }
    }
    
    return 0;
}


