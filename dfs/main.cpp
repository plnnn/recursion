#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector < int > g[N];
int used[N];

void dfs(int v) {
    cout << v << ' ';
    used[v] = 1;

    for (int to : g[v])
        if (!used[to]) dfs(to);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!used[i]) dfs(i);
    return 0;
}
