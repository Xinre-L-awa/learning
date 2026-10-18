#include <bits/stdc++.h>
using namespace std;

map<string,int> rank_of = {
    {"BangZhu",7},{"FuBangZhu",6},{"HuFa",5},
    {"ZhangLao",4},{"TangZhu",3},{"JingYing",2},{"BangZhong",1}
};

struct Person {
    string name, title;
    int cont, level, idx;
};

string title_by_rank(int r) { // r 从 1 开始（排除帮主副帮主后的名次）
    if (r <= 2)  return "HuFa";
    if (r <= 6)  return "ZhangLao";
    if (r <= 13) return "TangZhu";
    if (r <= 38) return "JingYing";
    return "BangZhong";
}

int main() {
    int n; cin >> n;
    vector<Person> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].title >> p[i].cont >> p[i].level;
        p[i].idx = i;
    }

    // 第一轮：排除帮主/副帮主，按 (帮贡↓, 输入顺序↑) 排序，重新分配职位
    vector<int> rest;
    for (int i = 0; i < n; i++)
        if (p[i].title != "BangZhu" && p[i].title != "FuBangZhu")
            rest.push_back(i);

    sort(rest.begin(), rest.end(), [&](int a, int b){
        if (p[a].cont != p[b].cont) return p[a].cont > p[b].cont;
        return p[a].idx < p[b].idx;
    });

    for (int r = 0; r < (int)rest.size(); r++)
        p[rest[r]].title = title_by_rank(r + 1);

    // 第二轮：全部人按 (职位↓, 等级↓, 输入顺序↑) 排序并输出
    sort(p.begin(), p.end(), [](const Person& a, const Person& b){
        int ra = rank_of[a.title], rb = rank_of[b.title];
        if (ra != rb) return ra > rb;
        if (a.level != b.level) return a.level > b.level;
        return a.idx < b.idx;
    });

    for (auto& x : p)
        printf("%s %s %d\n", x.name.c_str(), x.title.c_str(), x.level);
    return 0;
}