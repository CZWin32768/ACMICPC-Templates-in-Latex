#include<bits/stdc++.h>

using namespace std;

const int SIZE =300005;

int n, q;
vector<int> g[SIZE];
int sz[SIZE];
int res[SIZE];
int fa[SIZE];

void dfs(int u) {
    sz[u] = 1;
    res[u] = u;
    int mx = 0;
    for(int v: g[u]) {
        dfs(v);
        sz[u] += sz[v];
        if(sz[v] > sz[mx]) mx = v;
    }
    if(sz[mx] * 2 > sz[u]) {
        int t = res[mx];
        while((sz[u]-sz[t]) *2 > sz[u]) t = fa[t];
        res[u] = t;
    }
}

int main() {
    scanf("%d%d",&n, &q);
    for(int i = 2; i <= n; i++) {
        int a;
        scanf("%d",&a);
        fa[i] = a;
        g[a].push_back(i);
    }
    dfs(1);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", res[x]);
    }
    return 0;
}
